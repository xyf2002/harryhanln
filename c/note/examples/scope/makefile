CC=clang

all:

externalVariable: externalVariable.o testextern.o
	$(CC) -o externalVariable externalVariable.o testextern.o

externalVariable.o: externalVariable.c
	$(CC) -c externalVariable.c 

testextern.o: testextern.c 
	$(CC) -c testextern.c

clean:
	rm -rf *.o externalVariable
