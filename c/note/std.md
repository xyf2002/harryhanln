# C notes for Standard Library

## \<errno.h\>

### errno

- `int errno` is a global variable that is set by system calls and some library functions in the event of an error to indicate what went wrong.

- `void perror(const char *s)` prints a descriptive error message to stderr. The error message is preceded by the string `s`.

## \<stdlib.h\>

### Exiting

- `_Noreturn void exit(int status)` terminates the program immediately. The argument `status` is returned to the parent process. Functions passed to `atexit()` are called in reverse order. All C streams are flushed. Files created by `tmpfile` are removed.

- `void _Exit(int status)` is equivalent to `exit` except that it does not call functions passed to `atexit()` and does not flush streams.

- `void atexit(void (*func)(void))` registers the function `func` to be called when the program terminates normally. Functions are called in reverse order of registration.
