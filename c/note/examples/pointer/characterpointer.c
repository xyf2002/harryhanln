#include <stdio.h>
#include <string.h>

void mystrcpy(char * f, char * t){ // from, to
	while((*t=*f)!='\0'){
		t++; f++;
	}
}

int main() {
	char stra[20] = "Hello Pointers!";
	char strb[20];
	char * pstra = "Hello Pointers!";
	char * pstrb = "";

	char * aaa = stra;
	strcpy (strb, stra);
	// printf("%s: %s\n", stra, strb);
	// printf("%s\n", aaa);
	
	mystrcpy(pstra, pstrb);
    return 0;
}
