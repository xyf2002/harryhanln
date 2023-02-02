#include <stdio.h>

void swap(int * a, int * b){ //A function, pointer arguments enable a function the access and change the variable.
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int main() {
    int a = 1, b = 2;
	int * pa = &a;
	int * ppa = pa;
	// printf("pa: %d\n", &a); // *pa can be thought of an equivalent to a.
	// printf("a: %d; *pa: %d; b: %d\n", a, *pa, b);
	// b = *pa;
	// printf("a: %d; *pa: %d; b: %d\n", a, *pa, b);
	// (*pa)++;
	// printf("a: %d; *pa: %d; b: %d\n", a, *pa, b);
	// printf("a: %d; b: %d\n", a, b);
	// swap(&a,&b);
	// printf("a: %d; b: %d\n", a, b);
	//
	// int ar[] = {0,1,2,3,4,5};
	// int * par = ar; // name of an array is equivalent to the reference of its first element.
	// for (int i=0; i<6; ++i){
	// 	printf("*par: %d\n", *par);
	// 	par++;
	// }
	// printf("*par: %d\n", *par); // unsafe memory access
	// par--;
	// printf("*par: %d\n", *par); // unsafe address 

	// Some Pointer Arithmetic
	
	char * astr = "Hello, World!";
	char * pstr = astr;
	while (*pstr !='\0') ++pstr;
	printf("%ld\n", pstr-astr); // How to find the length of the string. 
	
	char fi= *astr;
	printf("%d %c\n", *astr, fi); // Notice the difference between d and c.
    return 0;
}	
