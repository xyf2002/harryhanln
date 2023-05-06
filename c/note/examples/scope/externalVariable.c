// compile with make externalVariable
#include <stdio.h>

int ex = 1;

void modex(){
	extern int ex;
	ex += 10;
	return;
}

void noextern(){
	int ex;
	ex = 100;
	for (int i = 0; i < 1; i++){
		printf("before declaration, ex refer to the one in function scope: %d\n", ex);
		int ex;  // This extern goes to the global variable
		ex = -1;
		printf("after sub declaration in for loop of noextern(), in for loop scope %d\n", ex++);
		for (int i = 0; i < 1; i++){
			extern int ex;
			printf("with extern, global scope: "
					"in subforloop for noexter(): %i\n", ex++);
		}
	}
	return;
}

int main(){
	extern int bbb; // note the declaration of external variable /global variable can appear later than its usage in the code.
	extern int ex;
	modex();
	noextern();
	printf("In main: %i \n", ex);  // ex = 12
	
	printf("bbb, another extern: %i \n", bbb);
	// int tobetested;
	// tobetested = 10;
	// printf("In main, tobetested declared as local variable: "
	// 			"%d\n", tobetested);
	extern int tobetested;
	printf("In main, tobetested declared as extern: %d\n", tobetested);
	return 0;
}

int bbb = 1;
