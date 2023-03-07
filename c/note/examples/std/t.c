// otherwise gcc with option -std=c11 complaints
//#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#define BILLION  1000000000L

long int currentns(){
	long int ns;
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);
	ns = spec.tv_nsec;
	return ns;
}


int main(){
    long int ns;
    uint64_t all;
    time_t sec;
    struct timespec spec;
	int ld;
	int buff2;
	int buff3;
	int buff4;
	char charbu;
	char nline = '\n';
	long long int intlistbuffer[100000];
	int intcounter[50] = {0,0,0,0,0,0,0,0,0};


	for (int i=0; i<100000; ++i){
		clock_gettime(CLOCK_REALTIME, &spec);
		sec = spec.tv_sec;
		ns = spec.tv_nsec;
	//	ld = ((uint64_t)currentns)%50;
		ld = (uint64_t)ns%197;
		clock_gettime(CLOCK_REALTIME, &spec);
		ns = spec.tv_nsec;
		buff2 = (uint64_t)ns%659;
		clock_gettime(CLOCK_REALTIME, &spec);
		ns = spec.tv_nsec;
		buff3 = (uint64_t)ns%167;



		intlistbuffer[i] = 659*197*buff3+ 659*ld+ buff2; 
		charbu = ld -'0';
		all = (uint64_t) sec * BILLION + (uint64_t) ns;
//		printf("Current time: %" PRIu64  " nanoseconds since the Epoch\n", all);
	}
	
	for (int i=0; i<100; ++i){
		printf("%i: %lli\n", i, intlistbuffer[i]);
	}
//	for (int i=0; i<50; ++i){
//		printf("%i: %i\n", i, intcounter[i]);
//	}
	FILE *fp = fopen("randint.txt", "r+");
	for (int i=0; i<100000; ++i){
	//	if (intlistbuffer[i] < 0) intlistbuffer[i] = -intlistbuffer[i]; 
		fprintf(fp, "%lli\n", intlistbuffer[i]);
	}
	fclose(fp);

	long time = all;
	printf("time is %ld", time);
    return 0;
}
