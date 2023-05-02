# C Quick Reference

## Declarations

### Pointer and Array

There are several ways to declare an array:
```c
int name[10];
int name [] = {1,2,3};
```

String is an array of char ended with `\0`; String can be declared with `""`
```c 
char * hello = "Hello, World";
char hi [] = {'h', 'i', '\0'};
char * hii ] = {'1', '2'}; // This can not work and will result in segamentation fault.
```

## Commonly Used Functions

### Dynamic Memory Allocation

```c 
// All of the following returns a void pointer. 
malloc(int) // 
calloc(int, type)
realloc(*void , int)
free(* void) // it does not frees the pointer, it frees the memory pointed to by the pointer
```

### IO 

- printf()
syntax: `printf("format%specifier", arg1, arg2, ...)`
specifiers:

`f` float
`d` decimal
`i` integer
`c` character
`s` string

- puts()
- scanf()
- getchar()
- putchar()
- fprintf()
- fscanf()
- fgetc()

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

## What C can not do

It does not seem that a function in C can automatically determine the length of an array. When passing array to a function, its length must be passed or the array shall end with a certain digit signifying its end.

Here is a list of things that C can not do:
- Functional Overloading


### Difference with C++

C has no namespaces.
C can not pass by reference.

