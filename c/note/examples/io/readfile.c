#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define _GNU_SOURCE 10000
#if !defined _POSIX_C_SOURCE || !defined _GNU_SOURCE
#define MYIMPLEMENTATION 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
ssize_t getline(char **restrict buffer, size_t *restrict size,
                FILE *restrict fp) {
  register int c;
  register char *cs = NULL;

  if (cs == NULL) {
    register int length = 0;
    while ((c = getc(fp)) != EOF) {
			length++;
			if (length%100==1){
	      cs = (char *)realloc(cs, 100*length+1);
			}
      if ((*(cs + length - 1) = c) == '\n') {
        *(cs + length) = '\0';
        *buffer = cs;
        break;
      }
    }
    return (ssize_t)(*size = length);
  } else {
    while (--(*size) > 0 && (c = getc(fp)) != EOF) {
      if ((*cs++ = c) == '\n')
        break;
    }
    *cs = '\0';
  }
  return (ssize_t)(*size = strlen(*buffer));
}
#endif

struct textbuf{
	char ** text;
	int lines;
};

int addtextbuf(struct textbuf * ptrtb, char * string){
	(ptrtb->lines)++;
	char ** ptrbuf = (char**)realloc(ptrtb->text, (ptrtb->lines)*sizeof(char*));
	ptrtb->text = ptrbuf;
	(ptrtb->text)[ptrtb->lines-1] = (char*)calloc(strlen(string)+1, 1);
	memcpy((ptrtb->text)[ptrtb->lines-1], string, strlen(string)-1);
	(ptrtb->text)[ptrtb->lines-1][strlen(string)] = '\0';
	// (ptrtb->text)[ptrtb->lines-1]=ptr;
	return 1;
}

int printTextBuf(struct textbuf * textbuf){
	for (int i = 0; i < textbuf->lines; i++){
		printf("%s\n", *((textbuf->text)+i));
	}
	return 1;
}

int main (){
	struct textbuf text;
	text.text=NULL;
	text.lines=0;

// #if MYIMPLEMENTATION>1
// 	printf("%s\n", "My Implementation USED!");
// #endif 

	FILE *fp = fopen("shakespeare.txt", "r");
	if (!fp) {printf("File can not be read! \n"); return -1;}

	char * buf;
	size_t size;

	buf = NULL; size = 0;
	int counter = 0;
	while (getline(&buf, &size, fp)>=1){
		addtextbuf(&text, buf);
		free(buf);
		buf = NULL; size = 0;
		// if (++counter > 100) break;
	}
	// printTextBuf(&text);	
	// getline(&buf, &size, fp);

// #if MYIMPLEMENTATION>1
// 	printf("%s\n", "My Implementation USED!");
// #endif 

	fclose(fp);
	return 0;
}
