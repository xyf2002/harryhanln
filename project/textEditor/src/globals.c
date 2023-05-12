#include "globals.h"
#include <stdlib.h>
struct editorConfig E;
struct programUtils PU;
textbuf TEXTBUF;

int textbufInit(textbuf *t) {
  t->size = 0;
  t->linebuf = NULL;
  if (t->size != 0 || t->linebuf != NULL)
		// exit(1);
    return -1;
  return 1;
}
