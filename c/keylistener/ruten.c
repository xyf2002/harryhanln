/// Code Inspired by Paige Ruten
/// https://github.com/paigeruten

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h> // lib for POSIX system

struct termios original;
int InitOriginal = 0;
void disableRAWMode();

int ESCPressed = 0;

/// This function enables RAW mode for terminal.
void enableRAWMode() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  tcgetattr(STDIN_FILENO, &original);
  atexit(&disableRAWMode); // From <stdlib.h> Execute the function when the
                           // program exits.
  InitOriginal = 1;
  raw.c_lflag &= ~(ECHO | ICANON); // Turn off echo mode. IE, output will not be
                                   // displayed while typing.
  // After exiting executable the ECHO mode may still be off
  // <Ctrl-c> and `reset` to reset.
  // ECHO is bitflag. ~ is binary NOT operator
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableRAWMode() {
  if (InitOriginal) // It is impossible to check if the struct is initialized or
                    // not by itself.
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

void *my_read() {
  char c;          // Buffer char for read()
  char buf[100];   // Buffer array for storing all char
  char *ptr = buf; // ptr for assignment of array
  enableRAWMode();
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
    printf("aaa\n");
    *(ptr++) = c;
  }
  printf("%s\n", buf);
  disableRAWMode();
  return NULL; // Recall NULL is a pointer to void that points to nothing
}

void * asciRead(){
	enableRAWMode();
	char ch;
	while((ch=getchar())!=27){
		printf("%c\n", ch);
		// usleep(1); // Sleeps a millisecond so that the thread is not taking all the cpu
	}
	ESCPressed = 1;
	printf("%s\n", "ESC Pressed!");
}

void *print() {
  while (!ESCPressed) {
    sleep(1);
    printf("%s\n", "I am Printing!\n");
  }
	printf("%s\n", "printing thread finished!");
	return NULL;
}

int main() {
  pthread_t id_print;
  pthread_t id_read;
  pthread_create(&id_print, NULL, print, NULL);
  pthread_create(&id_read, NULL, asciRead, NULL);
  pthread_join(id_print, NULL);
  pthread_join(id_read, NULL);
  return 0;
}
