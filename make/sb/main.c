#include <stdio.h>

extern char *name;

int main(void) {
	printf("%s\n", name);
	return 0;
}
