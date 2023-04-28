#include <ctype.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h> // lib for POSIX system

#define CTRL_KEY(k) ((k)&0x1f)

struct editorConfig {
  int screenrows;
  int screencol;
  struct termios orig_termios;
};

struct editorConfig E;

int getCursorPosition(int*, int*);
void getWindowSize(int*, int*);
void clearScreen();
void die (const char *s);
void enableRAWMode();
void disableRAWMode();
char editorReadKey();
void editorProcessKeyPress();
void editorRefreshScreen();
void editorInit();

/*** Terminal ***/
int getCursorPosition(int *rows, int *cols) {
  // Read the status report
  char c;
  char buf[32];
  int i = 0;

  if (write(STDIN_FILENO, "\x1b[6n", 4) != 4) {
    // Send query to device status report
    // report send back in stdin, in the form of "[37;57R" which can be read.
    // 37 col, 57 row
    die("func getCursorPosition failed!");
  }

  while (i < sizeof(buf) - 1) {
    if (read(STDIN_FILENO, &buf[i], 1) != 1)
      break;
    if (buf[i] == 'R')
      break;
    i++;
  }

  buf[i] = '\0';
  if (buf[0] != '\x1b' || buf[1] != '[')
    return -1;
  if (sscanf(&buf[2], "%d;%d", rows, cols) != 2)
    // sscanf from <stdio.h>
    return -1;

  return 0;
}

void getWindowSize(int *rows, int *cols) {
  struct winsize ws;

  // Use ioctl from <sys/ioctl.h>
  // place the data into ws struct, return -1 on failure
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) {
      // ESC 999C move cursor to right, B move down; They would not move cursor
      // off screen.
      die("Fail to get window size! (At func getWindowSize(), fail to write "
          "Escape Sequence");
    }
    getCursorPosition(rows, cols); // Seems to be working fine
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
  }
}

void clearScreen() {
  write(STDIN_FILENO, "\x1b[2J",
        4); // Erase in display, option 2, the whole screen, cursor do not move
  write(STDIN_FILENO, "\x1b[H",
        3); // Place the cursor the to top left of the screen
}

void die(const char *s) {
  clearScreen();

  perror(s); // From <stdio.h>
  exit(1);   // Exit with 1. From <stdlib.h>
}

/// This function enables RAW mode for terminal.
void enableRAWMode() {
  struct termios raw;
  if (tcgetattr(STDIN_FILENO, &raw) ==
      -1) { // STDIN_FILENO is the standard input
    die("tcgetattr");
  }
  if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) {
    die("tcgetattr");
  }
  atexit(&disableRAWMode); // From <stdlib.h> Execute the function when the
                           // program exits.
  raw.c_lflag &=
      ~(ECHO); // Turn off echo mode. IE, output will not be printed to screen
  raw.c_lflag &= ~(
      ICANON); // Turn off canonical mode, output will be registered immediately
  raw.c_lflag &= ~(ISIG); // Turn off <Ctrl-c> <Ctrl-z> which sends SIGINT and
                          // SIGTSTP to terminal repectively

  raw.c_lflag &= ~(IEXTEN); // Turn off <ctrl-v)
  raw.c_iflag &=
      ~(IXON); // Turn off <Ctrl-s> and <ctrl-q>, software flow control
  raw.c_iflag &= ~(ICRNL); // Carriage return now do not produce new line

  raw.c_oflag &= ~(
      OPOST); // Turn off all output processing. "\n" is not replaced by "\r\n"

  // Miscellaneous flags
  // This flags are probably alreadly disabled for modern terminal emulator
  raw.c_cflag &= ~(CS8);
  raw.c_iflag &= ~(BRKINT);
  raw.c_iflag &= ~(INPCK);
  raw.c_iflag &= ~(ISTRIP);

  // Timeout for Read

  raw.c_cc[VMIN] = 0;  // what read() returns after timeout
  raw.c_cc[VTIME] = 1; // Timeout after 0.1 s

  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
    die("tcsetattr");
  }
}

/// disable RAW Mode for the terminal.
void disableRAWMode() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1) {
    die("error occur in function disableRAWMode");
  }
}

/*** Append Buffer ***/
struct abuf {
  char *b;
  int len;
};

#define ABUF_INIT                                                              \
  { NULL, 0 }

void abAppend(struct abuf *ab, const char *s, int len) {
  char *new = realloc(ab->b, len + ab->len);

  if (new == NULL)
    return;
  memcpy(&new[ab->len], s, len); // From <string.h>
  ab->b = new;
  ab->len += len;
}

void abFree(struct abuf *ab) { free(ab->b); }

/*** Input ***/
/// Reads and returns the key once.
char editorReadKey() {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    // read returns '\0' if no input is received after 0.1 s
    // read returns number of byte read. -1 when failure.
    if (nread == -1 && errno != EAGAIN)
      die("editorReadKey failed!");

    // TEST: TESTCODE
    // printf("%s\r\n", "editorReadKey Running");
  }
  return c;
}

void editorProcessKeyPress() {
  char c = editorReadKey();
  switch (c) {
  case (CTRL_KEY('q')):
    clearScreen();
    exit('0');
    break;
  }
}

/*** Output ***/
void editorDrawRows(struct abuf *ab) {
  int nrows = E.screenrows;
  while (nrows-- > 0) {
    abAppend(ab, "~", 1);
    if (nrows > 0) {
      abAppend(ab, "\r\n", 2);
    }
  }
}

void editorRefreshScreen() {
  struct abuf ab = ABUF_INIT;

  abAppend(&ab, "\x1b[2J", 4);
  abAppend(&ab, "\x1b[H", 3);

  editorDrawRows(&ab);
  abAppend(&ab, "\x1b[H", 3);

  write(STDIN_FILENO, ab.b, ab.len);
}

/*** init ***/
void editorInit() { getWindowSize(&E.screenrows, &E.screencol); }

int main() {
  enableRAWMode();
  editorInit();
  while (1) {
    editorRefreshScreen();
    editorProcessKeyPress();
  }
  die("process died!");
  return 0;
}
