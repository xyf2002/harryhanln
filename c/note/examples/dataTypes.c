#include <stdio.h>
#define BELL '\xb'

void floatpointaccuracy(){
	float a = 0.1;
	float b = 0.2;
	double aa = 0.1;
	double bb = 0.2;
	long double aaa = 0.1;
	long double bbb = 0.2;
    printf("%10.20f\n", a+b);
	printf("%10.20f\n", aa+bb);
	printf("%10.20Lf\n", aaa+bbb);

	return;
}

void unsign(){
	unsigned long int int1 = 1111uL;
	printf("%li \n", int1); 
	printf("%li \n", sizeof(int1));
	return;
}

int main() {
	const int a= BELL; 
//	floatpointaccuracy();
//	unsign();
//	printf("%i\n", a);

// Conditional Statement
	int b = 200;
	int	c = (a>b) ? a : b; // if (a>b) is true, return a; else return b.
	printf("%i", c);

    return 0;
}
