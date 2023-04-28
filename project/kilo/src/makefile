CC=clang

all: a.out

a.out: main.o utils.o
	$(CC) main.o utils.o -o a.out

main.o: main.c utils.h utils.o
	$(CC) -c main.c 

utils.o: utils.c utils.h
	$(CC) -c utils.c

clean:
	rm -f utils.o main.o a.out
