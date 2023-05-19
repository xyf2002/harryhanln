#include "globals.h"

struct editorConfig E;
struct programUtils PU;
textbuf TEXTBUF;

int textbufInit(textbuf *t) {
  t->size = 0;
  t->linebuf = NULL;
  if (t->size != 0 || t->linebuf != NULL)
    return -1;
  return 1;
}

#include <string.h>
#include "utils.h"
static int addtextbuf(textbuf * ptrtb, char * string){
	(ptrtb->size)++;
	int stringLength = strlen(string);
	char ** ptrbuf = (char**)realloc(ptrtb->linebuf, (ptrtb->size)*sizeof(char*));
	ptrtb->linebuf = ptrbuf;
	(ptrtb->linebuf)[ptrtb->size - 1] = (char*)calloc(stringLength + 1, 1);
	memcpy((ptrtb->linebuf)[ptrtb->size - 1], string, stringLength - 1);
	(ptrtb->linebuf)[ptrtb->size - 1][stringLength]= '\0';
	return 1;
}

int textbufRead(textbuf *tb, FILE *fp) {
	char * buf;
	size_t size;

	buf = NULL; size = 0;
	while (getline(&buf, &size, fp)>=1){
		addtextbuf(tb, buf);
		free(buf);
		buf = NULL; size = 0;
	}
	return 1;
}

void textbufInputChar(textbuf *ptrtb, char c, int x, int y){
	char *linebuf = ptrtb->linebuf[y+1];
	int len = strlen(linebuf);
	linebuf=realloc(linebuf, len+1);
	// NOTE: UNFINISHED HERE
	// memmove(linebuf[x-1], linebuf[x], )
	linebuf[x-1]=c;
	ptrtb->linebuf[y+1]=linebuf;
}
