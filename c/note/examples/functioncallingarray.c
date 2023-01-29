#include <stdio.h>

void printl(int * li, int size){
	for (int i=0; i<size; ++i){
		printf("%i: %i\n",i, *li);
		++li;
	}
	printf("\n");
}

void add1 (int * li, int size){
	for (int i=0; i<size; ++i){
		++(*li);
		++li;
	}
}

int main(){
	int list[10] = {0};
	for (int i=0; i<10; ++i){
		list[i] +=i;
	}
	printl(list, 10);
	add1(list, 10);
	printl(list, 10);

}

