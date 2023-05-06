#include "terminal.h"
#include "utils.h"
#include "globals.h"

extern struct editorConfig E;

/// This function is merely an auxillary function for getWindowSize()
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
