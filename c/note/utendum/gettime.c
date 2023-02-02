#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#define BILLION 1000000000L

int main(){
	long int ns;
	uint64_t all;
	time_t sec;
	struct timespec spec;
	int ld;

	clock_gettime(CLOCK_REALTIME, &spec);
	sec = spec.tv_sec;
	ns = spec.tv_nsec;
	all = (uint64_t)sec*BILLION + (uint64_t)ns;
	printf("%ld\n", all);
}
