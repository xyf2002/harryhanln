#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp = fopen("read.txt", "r+");
	if (fp!=NULL){
		const char ch[] = "abbccci";
		const char cc[] = "\nabcdefg\n";
		const int integer[] = {1,2,3,4};
		char inc[5];
		inc[5] = '\n';

		for (int i=0; i<4; ++i){
			inc[i] = integer[i]+'0';
		}
		fputs(ch, fp);
		fputs(cc, fp);
		fputs(inc, fp);
		fclose(fp);
		return 0;
	}
	else{
		return -1;
	}
}
