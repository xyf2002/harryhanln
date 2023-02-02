#include <stdio.h>

int main() {
	int intlistbuffer [100] = {1};
	// Output to file.
   	FILE *fp = fopen("try.txt", "w"); // Open a file for writing. Create if not exist. Will over write file. `
	// 'a' for append, 
	for (int i=0; i<100; ++i){
	//	if (intlistbuffer[i] < 0) intlistbuffer[i] = -intlistbuffer[i]; 
		fprintf(fp, "%i\n", intlistbuffer[i]);
	}
	fclose(fp);

	// input to file
	int number;
	int lists[100000] = {0};
	FILE *fp2 = fopen("randint.txt", "r");

	if (!fp) {printf("File can not be read! \n"); return -1;}

	int counter = 0;
	while (fscanf(fp, "%d", &number)==1){
		lists[counter] = number;
		++counter;
	}
	fclose(fp);

    return 0;
}
