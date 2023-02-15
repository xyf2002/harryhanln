#include <stdio.h>

struct point{double x; double y;};

struct point ptinit(double a, double b){
	struct point temp;
	temp.x = a; temp.y = b;
	return temp;
}

void printpt(struct point *pp){
	printf("(%2.2f, %2.2f)\n", pp->x, pp->y);	
}

int main() {//int argc, char *argv[]
	struct point p1 = {10, 20};
	struct point p2 = ptinit(23, 22);
	struct point *ppt = &p2;
	printpt(ppt);

	printf("%f, %f\n", p1.x, p1.y);
	struct rectangle{struct point pt1, pt2;};
	return 0;
}
