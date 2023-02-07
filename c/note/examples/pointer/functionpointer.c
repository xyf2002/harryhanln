#include <stdio.h>

void add(int a, int b){
	printf("%d\n", a+b);
}
void minus(int a, int b){
	printf("%d\n", a-b);
}
void times(int a, int b){
	printf("%d\n", a*b);
}

void fun1(){
	printf("%s\n", "aha!");
}

void wrapper(void (*fun)()){
	fun();
}

int addint(int a, int b){
	return a+b;
}

int main() {//int argc, char *argv[]
	wrapper(fun1);
	int (*ptr)(int, int) = &addint;
	int sum = (*ptr)(2,3);
	printf("%i\n", sum);
	int sum2 = addint(2,3);
	printf("%i\n", sum2);
	printf("\n");
    void (*fun_ptr[])(int,int) = {add, minus, times};
	int ch, a = 15, b = 10;
	printf("%s\n", "0 for addition, 1 for substract, 2 for multiply");
	scanf("%d", &ch);
	(fun_ptr[ch])(a,b);

	return 0;
}
