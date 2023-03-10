# Fortran

## Hello, World!

Fortran is a compiled language. GCC contains fortran compiler which can be invoked with `gfortran`.

Each Fortran program must begin with `program <name>` and ends `end program <name>`. Here is a hello world program.

```Fortran
program helloworld

    print *, "Hello, World!"
    !This is comment.

end program helloworld
```

Comments in fortrans are preceeded by `!`.

N.B. Fortran is NOT case sensitive. Code with different cases will behave the same.

## Variables

Fortran is strong and statically typed language, each variable must have a type, and its type can not be changed.

Fortran variables must be declared at the beginning of the program. 

Fortran is NOT case sensitive.

There are five built in types:

- `integer`, like integer in C
- `real`, like floating point in C
- `complex`, a paired real number data type.
- `character`, like character in C
- `logical` like boolean in C

### Variables Declaration

```Fortran
    implicit none

    integer :: amount
    real :: pi, e
    complex :: frequency
    character :: initial
    logical :: isOkay=.false. !.true.
```

## Arrays

Fortran arrays are ONE indexed.

### Array Declarations and initializations

Static Array
```Fortran
    integer, dimension(10) :: array1
    integer :: array2(10) = (/2,2,3,4,5,6,7,8,9,10/)
    integer :: arrayb(10) = [1,2,3,4,5,6,7, 8,9,10]
    real, dimension(10, 10) :: array2d
```

Allocatable Array

```Fortran
    integer, allocatable :: array3(:)

    allocate(array3(50))
     
    array3(:) = 10
    deallocate(array3)
```

#### Array Slicing

```Fortran
  array1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  ! Array constructor
  array1 = [(i, i = 1, 10)]  ! Implied do loop constructor
  array1(:) = 0  ! Set all elements to zero
  array1(1:5) = 1  ! Set first five elements to one
  array1(6:) = 1  ! Set all elements after five to one

  print *, array1(1:10:2)  ! Print out elements at odd indices
  print *, array2(:,1)  ! Print out the first column in a 2D array
  print *, array1(10:1:-1)  ! Print an array in reverse
```

## String 

String declaration is similar to array

```Fortran
    character(len=4)::firstName
    character(len=5)::lastName='Smith'
    character(len=10)::fullName

    firstName = 'John'
    fullName=firstName//' '//lastName !concatenation 
```

Allocatable String
```Fortran
    character(:), allocatable :: longName(:)

    longName = "HarrySmith" ! allocate automatically
```
