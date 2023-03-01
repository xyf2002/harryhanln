#include <stdlib.h>
#include <iostream>
#include <vector>
// Note heap memory or free store is not an implmentation of the heap data structure

int main(){
	int a {0}; // Stored in the stack; note stack memory is a implmentation of the stack data structure
	// int *p;
	int *p = (int*)malloc(sizeof(int)); // Store the variable in heap.
	// malloc returns a void pointer to reference of the first at the heap.
	// Void pointer needs to be casted to the required pointer type.
	*p = 10;
	free(p); // heap must be cleared manually
	// malloc and free are C style code
	
	// cpp uses new and free 
	
	double *t = (double*)malloc(sizeof(double)*12);

	for (int i=0; i<5; ++i){
		t[i]=i+2;
	}
	for (int i=0; i<5; ++i){
		std::cout<<t[i]<<std::endl;
	}
	
	free(t);

	//calloc
	// Returns void pointer, and initialize all value to 0
	double * dd = (double*)calloc(5, sizeof(double)); // First argument: number of element, second: size
	
	dd = (double*)realloc(dd, 10*(sizeof(double))); // Reallocate the heap(ptr, size_of_heap)

	free(dd);
	
	int *l = new int; // type safe: returns a pointer of specific type.
	*l = 10;
	delete l;

	// l = new int[20];
	// delete[] l;

	return 0;
}
