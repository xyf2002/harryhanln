#include <stdio.h>
#include <string.h>

int* stripspace(char* lis, int len){
	int a[100];
	int counter=0;
	for (int i=0; i<len; ++i){ 
		if (lis[i]>'A' &&lis[i]<'z') {
			++counter;
			a[counter]=lis[i];
		}
	}
	int b[counter]={counter};
	for (int i=0; i<counter; ++i){
		b[i+1]=a[i];
	}

	return b;	
}

int main() {
	char dest[] = "Oh Love! Could you and I with Fate conspire\nTo grasp this sorry Schcem entire,\n"
		"Would not we shatter it to bites: and then\nRe-mould it nearer to the Heart's desire?";

	char buffer[10000]; // Create 2-dimensional array in the form of single dimensional array: step: 100.
	for (int i=0; i<1000; ++i){
		buffer[i]=' ';
	}
	

	int counter=0;
	char cache[100];
	int j=0;
	for (int i=0; i<strlen(dest)+1;i++){
		if (dest[i]=='\n'||dest[i]==':'||dest[i]=='.'||dest[i]=='!'||dest[i]==','||dest[i]=='\0'){
			for (int k=j; k<i; ++k){
				buffer[k+100*counter] = dest[k];
				printf("%c", dest[k]);
			}
			printf("\n");
			++counter;
			j=i+1;
		}
	}
	printf("\n\n\n");
	printf("%s", buffer);
	
//	for (int i=0; i<counter; ++i){
//		for (int l=0; l<100; ++l){
//			printf("%c", buffer[l+100*i]);
//		}
//		printf("\n");
//	}
	printf("%i", counter);
	printf("\n\n\n");
	char* aa = "aaaabbbba ";
	stripspace(aa, strlen(aa));



    return 0;
}
