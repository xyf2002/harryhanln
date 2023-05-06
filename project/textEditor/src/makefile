CC=clang
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

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
