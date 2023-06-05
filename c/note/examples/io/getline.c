/// my implementation of getline function compliant to C99 standard
/// LISCENSE GPL V3
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
      cs = (char *)realloc(cs, ++length+1);
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

int main() {
  FILE *fp = fopen("read.txt", "r");
  char *buf[10];
  size_t ibuf[10];
  int j = 0;
  for (;; j++) {
    //   buf[j] = malloc(60);
    // ibuf[j]=60;
    buf[j] = NULL;
    if (!getline(&buf[j], &ibuf[j], fp))
      break;
  }

  for (int i = 0; i < j; i++) {
    printf("len: %zu, %s", ibuf[i], buf[i]);
  }
  fclose(fp);

	if (buf[0][0]=='\n') printf("%s\n", "YES");

  return 0;
}
