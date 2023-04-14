#include <stdio.h>
#include <stdlib.h>

#define PRINTER(name) printer(#name, (name))

typedef struct {
	int d, m ,y;
	void (*addD)(void);
} Date ;

void printDate(Date * date){
	printf("DATE: %d; MONTH: %d; YEAR: %d\n", date->d, date->m, date->y);

	return;
}

Date * DateInit(int dd, int mm, int yy){
	Date * res = (Date *)malloc(sizeof(Date));
	res->d=dd;
	res->m=mm;
	res->y=yy;
	return res;
}

void printer(const char * str, double value){
	printf("%s: %lf\n", str, value);
	return;
}

int main() {//int argc, char *argv[]

	Date birthday;
	printDate(& birthday);
	birthday.d = 12;
	birthday.m = 12;
	birthday.y = 12;
	printf("%d\n", birthday.d);
	printDate(& birthday);

	
	double pi = 3.1415926f;
	PRINTER(pi);
	return 0;
}
