#ifndef GLOBALS_H
#define GLOBALS_H 1

#ifndef CTRL_KEY
#define CTRL_KEY(k) ((k)&0x1f)
#endif

#ifndef KILO_VERSION
#define KILO_VERSION "0.0.1"
#endif


#include <termios.h>
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

struct programUtils {
	int running;
};

#endif // for GLOBALS_H
