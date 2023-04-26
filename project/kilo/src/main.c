#include <ctype.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
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

void disableRAWMode();
void die(const char *);

void getWindowSize(int *rows, int *cols) {
  struct winsize ws;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    die("Fail to get window size! (At func getWindowSize())");
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
  }
}

void clearScreen() {
  write(STDIN_FILENO, "\x1b[2J", 4);
  write(STDIN_FILENO, "\x1b[H", 3);
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

/// Reads and returns the key once.
char editorReadKey() {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1 && errno != EAGAIN)
      die("editorReadKey failed!");
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

void editorDrawRows() {
  int nrows = E.screenrows;
  while (nrows-- > 0) {
    write(STDIN_FILENO, "~\r\n", 3);
  }
}

void editorRefreshScreen() {
  clearScreen();

  editorDrawRows();
  write(STDIN_FILENO, "\x1b[H", 3);
}

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
