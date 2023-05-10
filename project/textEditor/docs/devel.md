# Development Documentation

## `main.c` 

### `char editorReadKey(void)`

Read one key from `STDIN_FILENO`. Return char correspounding to normal keypress. If it is an escaped keypress (thus a special key), return the correspounding `enum editorkey`.

Here is a list of special keys:

- `ARROW_UP`: \x1b[A
- `ARROW_DOWN`: \x1b[B
- `ARROW_RIGHT`: \x1b[C
- `ARROW_LEFT`: \x1b[D
- `HOME`: \x1b[H
- `END`: \x1b[F
- `DELETE`: \x1b[3~
- `PAGE_UP`: \x1b[5~
- `PAGE_DOWN`: \x1b[6~

Note that the escape sequence is read in 3 parts, the first part is always
'\x1b', the second part is always '[', and the third part is the actual
escape sequence.

## `utils.h`

### `struct abuf {char *b, int len};` 

This struct is used like a string, with two function `abAppend` and `abFree` to append and free the string.

- `void abAppend(struct abuf *ab, const char *s, int len)` <br>
Append `len` characters from `s` to `ab->b` (realloc memory if required). `ab->len` is updated accordingly.

- `void abFree(struct abuf *ab)`<br> Free the memory of `ab`. 

### `ssize_t getline(char **lineptr, size_t *n, FILE *stream)`

My custom ISO compliant version of `getline()`. If `*lineptr` is `NULL` or `*n` is 0, then `getline()` will allocate a buffer for storing the line. This buffer should be freed by the user program even if `getline()` failed. 
