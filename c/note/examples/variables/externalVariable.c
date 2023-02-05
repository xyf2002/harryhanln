#include <stdio.h>

int ex = 1;

void modex(){
	extern int ex;
	++ex;
	return;
}
int main(){
	extern int bbb; // note the declaration of external variable /global variable can appear later than its usage in the code.

	modex();
	printf("%i \n", ex);
	
	printf("%i \n", bbb);
	return 0;
}

int bbb = 1;
