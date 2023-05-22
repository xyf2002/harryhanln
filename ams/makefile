all: o_bona.o
	gcc -o a.out o_bona.o -nostdlib -static

o_bona.o: bona.s
	as bona.s -o o_bona.o

clean: 
	rm *.o a.out
