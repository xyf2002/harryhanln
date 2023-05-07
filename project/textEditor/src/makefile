CC=gcc

CWARNINGS=-Wall -Wextra -Wpedantic -Wformat=2 -Wswitch-default -Wpointer-arith -Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wunreachable-code -Wlogical-op -Wfloat-equal -Wstrict-aliasing=2 -Wredundant-decls -Wold-style-definition 

COPTIMISING=-O0 -Og -ggdb3 -fno-omit-frame-pointer -ffloat-store -fno-common -fstrict-aliasing

CFLAGS=-std=c99 $(CWARNINGS) $(COPTIMISING) -lm

all: a.out

a.out: main.o utils.o terminal.o globals.o
	$(CC) $(CFLAGS) main.o utils.o terminal.o globals.o -o a.out 

main.o: main.c utils.o
	$(CC) $(CFLAGS) -c main.c 

terminal.o: terminal.c terminal.h utils.o
	$(CC) $(CFLAGS) -c terminal.c 

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c 

globals.o: globals.h globals.c
	$(CC) $(CFLAGS) -c globals.c 

test: a.out
	cp ./a.out -t ../test

clean:
	rm -f utils.o main.o a.out
