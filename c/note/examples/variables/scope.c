#include <stdio.h>

void pri(){
	int uns = 0;
	static int sa = 0;

	++uns; ++sa;
	printf("uns: %i; sa: %i\n", uns, sa);
}

int main() {
	int a = 1;
	{
		int a = 0;
		printf("in scope: %d\n",a);
	} 
	printf("out of scope: %d\n",a);
	for (int i=0; i<5; ++i){
		pri();
	}

    return 0;
}
