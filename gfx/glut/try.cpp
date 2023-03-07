#include <cstring>
#include <stdio.h>
#include "readFile.h"

int main(){

	char aaa[8092];
	readFile("try.txt", aaa);
	printf("%s\n", aaa);
	return 0;
}
