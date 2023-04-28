#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void clearScreen(void) {
  write(STDIN_FILENO, "\x1b[2J",
        4); // Erase in display, option 2, the whole screen, cursor do not move
  write(STDIN_FILENO, "\x1b[H",
        3); // Place the cursor the to top left of the screen
}

void die(const char *s) {
  clearScreen();

  perror(s); // From <stdio.h>
  exit(1);   // Exit with 1. From <stdlib.h>
}

#ifdef ABUF_INIT
void abAppend(struct abuf *ab, const char *s, int len) {
  char *new = realloc(ab->b, len + ab->len);

  if (new == NULL)
    return;
  memcpy(&new[ab->len], s, len); // From <string.h>
  ab->b = new;
  ab->len += len;
}

void abFree(struct abuf *ab) { free(ab->b); }
#endif
