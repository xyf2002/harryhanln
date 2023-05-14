CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 
LINKS=-lgsl -lgslcblas -lm
RTPATH=/usr/local/lib/

all: main.o
	$(CC) $(CFLAGS) main.o $(LINKS) -Wl,-rpath=$(RTPATH) 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

clean:
	rm -f *.o a.out
