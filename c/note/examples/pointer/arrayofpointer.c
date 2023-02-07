#include <stdio.h>

void writelines(char *lineptr[], int nlines){
	for (int i=0; i<nlines; ++i){
		printf("%s\n", lineptr[i]);
	}
}

int main() {
	char *lineptr[2]; //It is like an array of string. 

	*lineptr = "aa";
	*(lineptr+1) = "bb";

	writelines(lineptr, 2);

	int *integeri[3]; // an array of three pointers to integers
	
	
	return 0;
}
