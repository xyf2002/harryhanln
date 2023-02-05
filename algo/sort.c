#include <stdio.h>

int lists [100000] = {0};
int blist [100000] = {0}; // buffer list
int rlist [100000] = {0}; // Result list


int readfile(){
	int number;
	FILE *fp = fopen("randint.txt", "r");

	if (!fp) {printf("File can not be read! \n"); return -1;}

	int counter = 0;
	while (fscanf(fp, "%d", &number)==1){
		lists[counter] = number;
		++counter;
	}
	fclose(fp);
	return 0;
}

int testsort(){
	int number;
	int com[2] = {0};
	int * fir = com;
	int * sec = fir+1;
	int temp;
	int res = 1;
	int counter = 0;
	

	FILE *fp = fopen("sorted.txt", "r");
	if (!fp) {printf("File can not be read! \n"); return -1;}

	while (fscanf(fp, "%d", &number)==1){
		if(counter==0) *sec=number;
		else{ 
			*fir = *sec; *sec = number;	
			if (*sec<*fir){
				res = 0;
				break;
			}
		}
		++counter;

	}
	fclose(fp);
	if(res) printf("All sorted right!\n");
	else printf("Sorting failed!\n");
	return 0;
}

void cpblist(){
	int * pli = lists;
	int * pbli = blist;
	for (int i=0; i<99999; ++i){
		*pbli = *pli;
		pbli++; pli++;
	}
	*pbli = *pli;
}

int max(){
	int * pbli = blist;
	int max= *pbli;
	int counter = 0;
	for (int i=0; i<99999; ++i){
		pbli++;
		if(*pbli>max){
			max = *pbli;
			counter = i+1;
		}
	}
	// printf("%d\n", counter);
	return max;
	
}
int min(){
	int * pbli = blist;
	int min = *pbli;
	int counter = 0;
	for (int i=0; i<99999; ++i){
		pbli++;
		if(*pbli<min){
			min = *pbli;
			counter = i+1;
		}
	}
	// printf("%d\n", counter);
	return min;
	
}

void gemin(int * li, int len, int init, int * res){
	int * pbli = li;
	int min = 21680228;
	int counter = 0;
	for (int i=0; i<len-1; ++i){
		pbli++;
		if (*pbli<=init) continue;
		if((*pbli<min)){
			min = *pbli;
			counter = i+1;
		}
	}
	// printf("%d\n", counter);
	*res = min;
	return;
	
}

void mysort(){ //This algorithm takes ~18 sec (unoptimized, ¬6 for -O3 optimization) for the given data set. Moreover, it does not work for repeated value.
	cpblist(); //blist is  the list with entries; Length 1000000
	int * pt = rlist;
	int temp=0;
	int temp2=0;
	for (int i=0; i<100000; ++i){
		gemin(blist, 100000, temp, &temp2);
		*pt = temp2;
		//printf("temp2: %d\n", temp2);
		temp = temp2;
		pt++;
	}
	

	return;
}


int main (){

	readfile();
	cpblist();

	// for(int i=0; i<10000; ++i){
	// 	printf("%i: %d; %d\n",i , lists[i], blist[i]);
	// }
	
	int tmin = min();
	printf("minimum is :%d \n", tmin);
	int tmax = max();
	printf("max is: %d \n", tmax);

	mysort();
	int * ptr = rlist;
	for (int i=0; i<100; ++i){
		printf("%d: %d\n", i, *ptr);
		ptr++;
	}
	// file output
	FILE *fp = fopen("sorted.txt", "r+");
	for (int i=0; i<100000; ++i){
		fprintf(fp, "%i\n", rlist[i]);
	}
	fclose(fp);

	testsort();
	return 0;
}
