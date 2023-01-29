#include <stdio.h>

int main (){

	int number;
	int lists[100000] = {0};
	FILE *fp = fopen("randint.txt", "r");

	if (!fp) {printf("File can not be read! \n"); return -1;}

	int counter = 0;
	while (fscanf(fp, "%d", &number)==1){
		lists[counter] = number;
		++counter;
	}
	fclose(fp);
	for(int i=0; i<100000; ++i){
		printf("%i: %d\n",i , lists[i]);
	}
	return 0;
}
