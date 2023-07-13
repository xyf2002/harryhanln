CFLAGS=$(shell pkg-config --cflags gtk4) 
LIBS=$(shell pkg-config --libs gtk4)

CC=gcc

all: main.o
	$(CC) main.o -o main $(LIBS)
	
main.o: main.c 
	gcc $(CFLAGS) main.c -c 

clean:
	rm -f *.o main

