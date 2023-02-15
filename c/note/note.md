c notes
-----

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

## Scopes

External Variable last for the whole file they are declared in.

## Concepts to Learn

### Bitwise Operators

`&` bitwise and
`|` bitwise or
`^` bitwise xor
`~` bitwise not
`<<` left shift
`>>` right shift

### goto and label

### Pointers
Function pointers.

# What C can not do

It does not seem that a function in C can automatically determine the length of an array. When passing array to a function, its length must be passed or the array shall end with a certain digit signifying its end.

# Difference with C++

C has no namespaces.
