# c notes

### printf()
syntax: `printf("format%specifier", arg1, arg2, ...)`
specifiers:

`f` float
`d` decimal
`i` integer
`c` character
`s` string

## functions

All c function by default are called by value, i.e, a new local variable is created for the function and the value of the argument is copied into it. To pass by reference, use `&` before the argument.

However, arrays are passed by reference by default.
