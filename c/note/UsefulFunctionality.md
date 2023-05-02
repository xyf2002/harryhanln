# Useful Functionality in C STD

## String Manipulation

### Concatenation

- `int snprintf( char *restrict buffer, size_t bufsz,
              const char *restrict format, ... );`  Concatenate strings with a format string. C99, from `stdio.h`. Returns the number of characters written, or -1 on error.
