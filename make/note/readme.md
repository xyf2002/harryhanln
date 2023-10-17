# Guide for GNU-Make

## Quick Start

Make is a program that automates compilation, linking, and build from source code, usually C or C++, but can be any complied languages. 

The rules of compilation and linking are written in user-created `Makefile`. Invode make in the same directory to execute it.

## Variable

`$$` is a escaped dollar sign

### Automatic variables

- `$@` is the target name
- `$<` is the first prerequisite
- `$^` is all prerequisites

### Wild card expansion

Wild card expansion does not occur on variable assignment. Use wildcard function: `foo := $(wildcard *.o)`.

## Rules

### Wildcard

Wildcard expansion occur automatically in rules, but not in variable assignment.

### Searching Directive for Prerequisite

Some times the source file ans the binaries are placed in different directories. Make file will search all directories listed in the variable `VPATH` for the targets and prerequisites. 

VPATH shall contain directories separated by colon or space. `VPATH = src:../headers`


## Some Makee functions

### patsubst

## Some Niches of gnu-make

- Each line of the make file are running in separte shells. To run in the same shell, write `.ONESHELL:` in the beginning of the file.

- Order only prerequisite


