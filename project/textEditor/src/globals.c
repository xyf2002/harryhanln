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

// BUG: Assigne place out of range
void textbufInputChar(textbuf *ptrtb, char inputChar, int x, int y){
	char *linebuf = ptrtb->linebuf[y+1];
	// strlen does not count the final null terminator.
	int len = strlen(linebuf);  
	linebuf=realloc(linebuf, len+2); // extra space for null terminator
	// memmove: <string.h>, c11
	memmove(&linebuf[x], &linebuf[x-1], (len-x+1)*sizeof(char));
	linebuf[x-1]=inputChar; // Assign Character
	linebuf[len+1] = '\0'; 
	ptrtb->linebuf[y+1]=linebuf;
}

// NOTE: UNFINSIHED
void textbufDeleteChar(textbuf *ptrtb, int x, int y){
	char *linebuf = ptrtb->linebuf[y+1];
	// strlen does not count the final null terminator.
	int len = strlen(linebuf);  
	linebuf=realloc(linebuf, len+2); // extra space for null terminator
	// memmove: <string.h>, c11
	memmove(&linebuf[x-1], &linebuf[x], (len-x+1)*sizeof(char));
	linebuf[len+1] = '\0'; 
	ptrtb->linebuf[y+1]=linebuf;
}
