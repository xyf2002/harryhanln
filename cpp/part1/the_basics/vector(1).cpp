#include <stdio.h>

struct Vector
{
	int sz;
	double* elem;
};

void vector_init(Vector& v, int s)
{
	v.elem = new double [s];
	v.sz = s;
}

void vector2d_init(Vector& v, double a, double b)
{
	vector_init(v, 2);
	v.elem[0] = a;
	v.elem[1] = b;
}

void printvec(Vector vec)
{
	for (int i = 0; i != vec.sz; i++ ){
		printf("%f ", vec.elem[i]);
	}
	printf("\n");
}

Vector vector2d_addition(Vector a, Vector b)
{
	Vector res;
	if (a.sz != b.sz){
		return res;
		printf("Vectors differ in sizes! \n");
	}
	
	vector2d_init(res, a.elem[0]+b.elem[0], a.elem[1]+b.elem[1]);

	return res;
}

int main(){
	int a,b;
	a = 1; b = 2;

	Vector v1, v2, v3;
	vector2d_init(v1, 1, 1);
	vector2d_init(v2, 2, 2);
		
	printvec(v1);

	return 0;


}
