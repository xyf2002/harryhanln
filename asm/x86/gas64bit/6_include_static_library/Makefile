a.out: object_main.o
	ld object_main.o

object_main.o: main.asm
	as --64 -o object_main.o main.asm

clean:
	rm -f *.o a.out
