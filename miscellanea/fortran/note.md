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

## Arrays

Fortran arrays are ONE indexed.
