a.out: object_main.o
	ld -e _start object_main.o # -e _start tells linker entry point is _start

object_main.o: main.asm
	as --64 -o object_main.o main.asm

clean:
	rm -f *.o a.out
