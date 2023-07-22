a.out: helloWorld.o
	ld -m elf_i386 -o a.out helloWorld.o

helloWorld.o: helloWorld.asm
	nasm -f elf  helloWorld.asm
	
clean:
	rm -f *.o a.out
