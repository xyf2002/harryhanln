// This script tries to demonstrate the effect of cpu caches.

// My cpu has 48 * 8 L1d, 1280 kb * 8 L2, 24 MB L3
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define POINTER_PER_KB 128  // one pointer is 8 byte
#define TEST_SIZE 2500 // test size in kb
#define KILO 1028
#define MEGA 1028 * 1028

// Holds the pointer chain
int ***ARRAY [TEST_SIZE*POINTER_PER_KB];

/* current time in microseconds. 1,000,000 us is one sec */
long uTime()
{
  struct timeval tp; // timeval defined in sys/time.h
  gettimeofday(&tp, NULL);
  return tp.tv_sec*(long)(1000000) + tp.tv_usec;
}

void init()
{
	// this array holds pointer to pointers
	// each pointer points to the next
	// we are chasing pointers through this array
	// ARRAY = (int***)malloc(TEST_SIZE * KILO);

	int num = TEST_SIZE * POINTER_PER_KB;
	for (int i = 0; i < num ; ++i){
		if (i == num - 1) {
			// make the pointer chain circular
			ARRAY[i] = &ARRAY[0];
			break;
		}
		ARRAY[i] = &ARRAY[i+1];
	}
}

void cleanUp()
{
	// free(ARRAY);
}

// repeat n times, with size kb
void chasePointer(int n, size_t size)
{
	int **ptr = ARRAY[0];
	int **ptr2;
	int counter = 0;

	// shortens the chain so that total number of memory fits in size kb
	int index = size * POINTER_PER_KB;
	ARRAY[index] = & ARRAY[0];

	// warm up and check of the pointer chains is circular
	do {
		ptr = *ptr;
		counter++;
	} while(ptr!=&ARRAY[0]);

	printf("Pointer Chain of Length %d  ", counter);
	
	double time = uTime();
	for (int i = 0; i < n/2; ++i){
		// pointer chasing
		ptr2 = *ptr;
		ptr = *ptr2;
	}
	time = uTime() - time;

	printf("Size: %d Kb; Time Used Per Pointer Chasing: %lf (us)\n",
			size, time / (float)n);
	
	// restore the long chain
	ARRAY[index] = & ARRAY[index+1];
}

int main ()
{
	init();

	int test_sizes[] = 
		{1,  2,  3,   4,   5,   10,  20,  40,   41,   42,   50,
		55, 60, 128, 256, 300, 800, 900, 1000, 1200, 1300, 1400};

	for(int i = 1; i < sizeof(test_sizes)/sizeof(int); i++){
		chasePointer(100*MEGA, test_sizes[i]);
	}
	// chasePointer(1000*MEGA, TEST_SIZE);

	cleanUp();
	return 0;
}
