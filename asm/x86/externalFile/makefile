a.out: main.o
	ld -m elf_i386 -o a.out main.o

main.o: main.asm
	nasm -f elf  main.asm
	
clean:
	rm -f *.o a.out
