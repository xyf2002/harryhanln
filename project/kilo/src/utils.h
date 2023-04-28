#ifndef UTILS_H
#define UTILS_H 1

// append buffer: my custom mutable strings in C
#ifndef ABUF_INIT
#define ABUF_INIT                                                              \
  { NULL, 0 }

struct abuf {
  char *b;
  int len;
};

void abAppend(struct abuf *, const char *s, int len);
void abFree(struct abuf *ab);
#endif

// Utilities functions
void clearScreen(void);
void die(const char *);

#endif // For UTILS_H
