CC=clang
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

all: a.out

a.out: main.o utils.o
	$(CC) main.o utils.o -o a.out $(CFLAGS)

main.o: main.c utils.h utils.o
	$(CC) -c main.c $(CFLAGS)

utils.o: utils.c utils.h
	$(CC) -c utils.c $(CFLAGS) 

clean:
	rm -f utils.o main.o a.out
