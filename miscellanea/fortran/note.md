# Fortran Note

## Compiler

`gfortran`, the gnu fortran compiler can be used.

## Variable

Fortran is statically and strong type language. Each variable must have a type, which can not be changed during the program.

All variables must be declared!

Need `implicit none` tells the program all variable must be explicitly declared. always include it.

### Types

- Integer: data representing whole numbers, positive or negative.
- real: for floating point numbers
- complex: a doublet of real
- character: for text data
- logical: equivalent to boolean


### Array declaration

```
integer, dimension(10) :: array 
integer :: array2 (5)

array2 = [1,2,3,4,5]
```

Array is declare with `[]`, like python

## Subroutine

Subroutine is like function
