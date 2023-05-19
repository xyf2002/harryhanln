#ifndef GLOBALS_H
#define GLOBALS_H 1

#ifndef CTRL_KEY
#define CTRL_KEY(k) ((k)&0x1f)
#endif

#define KILO_VERSION_MAJOR 0
#define KILO_VERSION_MINOR 0
#define KILO_VERSION_PATCH 1

#include <termios.h>
typedef struct {
  int size;
  char *chars;
} erow; // editor row

typedef struct {
  // TODO: Change size to numlines
  int size;       // Total number of lines
  char **linebuf; // A pointer storing pointer to line buffer
} textbuf;        // textbuffer holding all lines.

#include <stddef.h>
int textbufInit(textbuf *);

#include <stdio.h>
int textbufRead(textbuf *, FILE *);

enum editorKey {
  ARROW_LEFT ,
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
  int screenrows; // number of rows that fit in the screen
  int screencols; // number of columns that fit in the screen
  int offsetx;  // Display offset, x direction
  int offsety;
	int mode;  // Indicator for mode 
  struct termios orig_termios;
};

struct programUtils {
  int running;
  int updated;
};

void textbufInputChar(textbuf *, char, int x, int y);
#endif // for GLOBALS_H
