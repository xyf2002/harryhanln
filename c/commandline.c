#include <stdio.h>

// void *v: generic pointers
// pointer to functions
void qsort(void *v[], int left, int right, int(*comp)(void *, void *)){

	return;
}

int main(int argc, char *argv[]){//int argc, char *argv[]
	int a = argc;
	while(argc>0){
		printf("%s%s", argv[a-argc], (argc>1)?" ":"\n");
		argc--;
	}

	argc = a;
	while(argc>0){
		printf("%s%s", *argv++, (argc>1)?" ":"\n");
		argc--;
	}

	return 0;
}
