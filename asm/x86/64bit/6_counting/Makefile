a.out: object_file_main.o
	ld -o a.out object_file_main.o

object_file_main.o: main.asm function.asm
	nasm -felf64 -o object_file_main.o main.asm
	
clean:
	rm -f *.o a.out
