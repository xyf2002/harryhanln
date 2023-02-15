#include <stdio.h>

double v1 [] = {1,2,3,4,5}; 
double v2 [] = {1,4,5,2,3}; 
double * res []={v1,v2};

void dpro(double * v1, double * v2, double * res[]){
	if (sizeof(v1)!=sizeof(v2)){
		fprintf(stderr, "unmatched size!");
	}
	long int size = sizeof(v1)/sizeof(*v1);
	printf("%ld\n", size);

}



int main() {//int argc, char *argv[]
	printf("%s\n", "Hello, world!");
	printf("%ld\n", sizeof(v1)/sizeof(double));
	dpro(v1,v2, res);
	// fprintf(stderr, "ERROR: wrong!\n");
	return 0;
}
