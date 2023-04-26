#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h> // lib for POSIX system

struct termios terminalInitState;
void disableRAWMode();

int exitPrint = 0;

void die(const char *s) {
  perror(s); // From <stdio.h>
  exit(1);   // Exit with 1. From <stdlib.h>

  // perror looks for the global variable errno an prints a description of the
  // error. When error occurs in program, the program set the global errno
  // variable. it also takes a string which it also prints if the error occur.
}

/// This function enables RAW mode for terminal.
void enableRAWMode() {
  struct termios raw;
  if (tcgetattr(STDIN_FILENO, &raw) ==
      -1) { // STDIN_FILENO is the standard input
    die("tcgetattr");
  }
  if(tcgetattr(STDIN_FILENO, &terminalInitState)==-1){
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

  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;

  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw)==-1){
		die("tcsetattr");
	}
}

void disableRAWMode() {
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminalInitState)==-1){
		die("error occur in function disableRAWMode");
	}
}

void *my_read() {
  char c;          // Buffer char for read()
  char buf[100];   // Buffer array for storing all char
  char *ptr = buf; // ptr for assignment of array
  enableRAWMode();
  // read return number of bytes if success. 0 if EOF, -1 if fail.

  while (1) {
    if(read(STDIN_FILENO, &c, 1)==-1){
			die("Error for read() inside my_read");
		}

    if ((int)c != 0) {
      if (iscntrl(c)) { // From <ctype.h> test if it is control character
        printf("%d\r\n\r", c);
      } else {
        printf("%d: ('%c')\r\n\r", c, c);
        *(ptr++) = c;
      }
    }

    if (c == 'q') {
      printf("%s\r\n\r", buf);
      break;
    }
    c = 0;
  }

  exitPrint = 1;
  disableRAWMode();
  // return NULL; // Recall NULL is a pointer to void that points to nothing
  // return NULL is optional
}

void *asciRead() {
  enableRAWMode();
  char ch;
  while ((ch = getchar()) != 27) {
    printf("%c\n", ch);
    // usleep(1); // Sleeps a millisecond so that the thread is not taking all
    // the cpu
  }
  exitPrint = 1;
  printf("%s\n", "ESC Pressed!");
}

void *print() {
  while (!exitPrint) {
    sleep(1);
    printf("%s\n", "I am Printing!\n");
  }
  printf("%s\n", "printing thread finished!");
  return NULL;
}

int main() {
  pthread_t id_print;
  pthread_t id_read;
  // pthread_create(&id_print, NULL, print, NULL);
  pthread_create(&id_read, NULL, my_read, NULL);
  // pthread_join(id_print, NULL);
  pthread_join(id_read, NULL);
  return 0;
}
