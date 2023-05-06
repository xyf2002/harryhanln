#include <ctype.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h> // lib for POSIX system

#include "utils.h"

#define CTRL_KEY(k) ((k)&0x1f)
#define KILO_VERSION "0.0.1"

typedef struct {
  int size;
  char *chars;
} erow; // editor row

enum editorKey {
  ARROW_LEFT = 100,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  PAGE_UP,
  PAGE_DOWN,
  DEL_KEY,
  HOME_KEY,
  END_KEY
};

struct editorConfig {
  int cx, cy;     // cursor position. cx horizantol, cy vertical
  int screenrows; // number of rows in the screen
  int screencols; // number of columns in the screen
  int numrows;
  erow row;
  struct termios orig_termios;
};

struct editorConfig E;

int getCursorPosition(int *, int *);
void getWindowSize(int *, int *);
void enableRAWMode(void);
void disableRAWMode(void);
char editorReadKey(void);
void editorProcessKeyPress(void);
void editorRefreshScreen(void);
void editorInit(void);
int editorMoveCursor(char);

/*** FILE IO ***/
void editorOpen(char *filename) {
	FILE *fp = fopen(filename, "r"); 
	char errorMessage [100];
	snprintf(errorMessage, 100, "Can not open File '%s'\r\nperrer message", filename );
	if (!fp) die(errorMessage);

  char *line = NULL;  // if *line = NULL getline will automatically allocate memory for it.
	size_t linecap = 0;
  ssize_t linelen = getline(&line, &linecap, fp);
	if (linelen != -1){
		while ((linelen > 0) && ((line[linelen-1]== '\n' )||(line[linelen-1]== 'r')))
			linelen--;
	}

  E.numrows = 1;
  E.row.size = linelen;
  E.row.chars = (char *)calloc(linelen + 1, sizeof(char)); 
  memcpy(E.row.chars, line, linelen);
  E.row.chars[linelen] = '\0';

	free(line);
	fclose(fp);
}

/*** Terminal ***/
int getCursorPosition(int *rows, int *cols) {
  // Read the status report
  char buf[32];
  unsigned int i = 0;

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

/// This function enables RAW mode for terminal.
void enableRAWMode(void) {
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
void disableRAWMode(void) {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1) {
    die("error occur in function disableRAWMode");
  }
}

/*** Input ***/
/// Reads and returns the key once.
// Note on Escape Sequences:
// ARROW_UP: \x1b[A
// ARROW_DOWN: \x1b[B
// ARROW_RIGHT: \x1b[C
// ARROW_LEFT: \x1b[D
// HOME: \x1b[H
// END: \x1b[F
// DELETE: \x1b[3~
// PAGE_UP: \x1b[5~
// PAGE_DOWN: \x1b[6~
// Note that the escape sequence is read in 3 parts, the first part is always
// '\x1b', the second part is always '[', and the third part is the actual
// escape sequence.
char editorReadKey(void) {
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

  if (c != '\x1b') // if no escape sequence is read.
    return c;

  char seq[3];
  if (read(STDIN_FILENO, &seq[0], 1) != 1)
    return '\x1b';
  if (read(STDIN_FILENO, &seq[1], 1) != 1)
    return '\x1b';
  read(STDIN_FILENO, &seq[2], 1);

  if (seq[0] != '[')
    return '\x1b';

  if ((seq[1] == '5') && (seq[2] == '~'))
    return PAGE_UP;
  if ((seq[1] == '6') && (seq[2] == '~'))
    return PAGE_DOWN;
  if ((seq[1] == '3') && (seq[2] == '~'))
    return DEL_KEY;
  if ((seq[1] == '1') && (seq[2] == '~'))
    return HOME_KEY;

  switch (seq[1]) {
  case 'A':
    return ARROW_UP; // TESTED
  case 'B':
    return ARROW_DOWN; // TESTED
  case 'C':
    return ARROW_RIGHT; // TESTED
  case 'D':
    return ARROW_LEFT; // TESTED
  case 'H':
    return HOME_KEY; // TESTED
  case 'F':
    return END_KEY;
  }
  return '\x1b';
}

void editorProcessKeyPress(void) {
  char c = editorReadKey();
  switch (c) {
  case (CTRL_KEY('q')):
    clearScreen();
    exit('0');
    break;
  case ARROW_LEFT:  // TESTED
  case ARROW_RIGHT: // TESTED
  case ARROW_DOWN:  // TESTED
  case ARROW_UP:    // TESTED
    editorMoveCursor(c);
    break;

  case PAGE_UP: // PAGE_UP, PAGE_DOWN tested
  case PAGE_DOWN: {
    int times = E.screenrows;
    while (times--)
      editorMoveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
    break;
  }

  case HOME_KEY: // TESTED
  case END_KEY:  // TESTED
  case DEL_KEY:  // TESTED
    break;
  }
}

/*** Output ***/
void editorDrawRows(struct abuf *abptr) {
  int nrows = E.screenrows;

  while (nrows--) { // This loop will repeat nrows times
    if (E.screenrows - nrows > E.numrows) {
      if (nrows == 2 * E.screenrows / 3) {
        // Welcome Message
        char welcome[80];
        int welcomelen = snprintf(welcome, sizeof(welcome),
                                  "Kilo Editor -- Version %s", KILO_VERSION);
				// KILO_VERSION defined in main.c
        // snprintf is form <stdio.h>
        if (welcomelen > E.screencols)
          welcomelen = E.screencols;

        // Center the Message
        int padding = (E.screencols - welcomelen) / 2;
        if (padding) {
          abAppend(abptr, "~", 1);
          padding--;
        }
        while (padding--)
          abAppend(abptr, " ", 1);

        abAppend(abptr, welcome, welcomelen);
      } else {
        abAppend(abptr, "~", 1);
      }
    } else {
			int len = (E.row.size>E.screenrows ? E.screenrows : E.row.size);
			abAppend(abptr, E.row.chars, len);
			free(E.row.chars);
    }

    abAppend(abptr, "\x1b[K", 3); // Erase line to right of the cursor
    if (nrows > 0) {
      abAppend(abptr, "\r\n", 2);
    }
  }
}

void editorRefreshScreen(void) {
  // init append buffer
  struct abuf ab = ABUF_INIT;

  abAppend(&ab, "\x1b[?25l", 6); // Hide cursor
  abAppend(&ab, "\x1b[H", 3);    // Move cursor to top left

  editorDrawRows(&ab);

  // Move mouse to correct position
  char buf[32];
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
  abAppend(&ab, buf, strlen(buf)); // To corrected position
                                   // strlen is from <string.h>

  abAppend(&ab, "\x1b[?25h", 6); // Show cursor
  write(STDIN_FILENO, ab.b, ab.len);
}

int editorMoveCursor(char key) {
  switch (key) {
  case ARROW_UP:
    if (E.cy > 0)
      E.cy--;
    return 0;
  case ARROW_DOWN:
    if (E.cy < E.screenrows - 1)
      E.cy++;
    return 0;
  case ARROW_LEFT:
    if (E.cx > 0)
      E.cx--;
    return 0;
  case ARROW_RIGHT:
    if (E.cx < E.screencols - 1)
      E.cx++;
    return 0;
  }
  return -1;
}

/*** init ***/
void editorInit(void) {
  E.cx = 0;
  E.cy = 0;
  E.numrows = 0;
  getWindowSize(&E.screenrows, &E.screencols);
}

int main(int argc, char *argv[]) {
  enableRAWMode();
  editorInit();
	if (argc > 1){
  editorOpen(argv[1]);
	}
  while (1) {
    editorRefreshScreen();
    editorProcessKeyPress();
  }
  die("process died!");
  return 0;
}
