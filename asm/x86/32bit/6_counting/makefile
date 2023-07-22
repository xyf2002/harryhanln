a.out: main.o
	ld -o a.out main.o

main.o: main.asm function.asm
	nasm -felf64  main.asm
	
clean:
	rm -f *.o a.out
