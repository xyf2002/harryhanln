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

