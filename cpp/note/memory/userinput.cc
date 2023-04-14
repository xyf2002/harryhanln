#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

int main(){
	srand(time(NULL));
	int n;
	printf("How many integer would you want?\n");
	scanf("%d", &n);
	int* ptr = (int*)malloc(n*sizeof(int));
	for (int i=0; i<n; ++i){
		ptr[i]=rand();
	}
	for (int i=0; i<n; ++i){
		printf("%-4d: %d\n",i, ptr[i]);
	}

	free(ptr);

	return 0;
}
