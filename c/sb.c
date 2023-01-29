#include <stdio.h>

int main(){
	int li [10];
	for (int i=0; i<10; ++i){
		li[i]++;
		printf("%i\n", li[i]);
	}
	int a = 123;
	char * b = a - '0';
	printf("%c\n", b);
	return 0;
}
