#include <iostream>
#include <stdio.h>
using namespace std;

double square (double x)
{
	return x*x;
}

void print(double x)
{
	cout << "the square of " << x << " is " << square(x)<<endl;
}

bool accept()
{
	cout<<"Do you want to proceed or not?" << endl;

	char answer = 0;
	cin >> answer;

	if (answer == 'y') return true;
	return false;
}

bool accept1 ()
{
	cout<<"Do you accept?"<< endl;
	char answer = 0;
	cin >> answer;

	switch(answer){
	case 'y':
		return true;
	case 'n':
		return false;
	}
	cout<<"is that a no?"<<endl;
	return false;
}


int count_x(int* p, int x)
{
	if (p==nullptr) return 0;
	int count = 0;
	for (; *p!=0; ++p)
		if (*p ==x)
			++count;
	return count;
}

struct Vector{
		int sz;
		double* elem;
}; //note the final ;

void vector_init(Vector& v, int s)
{
	v.elem = new double[s]; // new operator returns the pointer to a double[s], recall elem is a pointer;
	v.sz = s;
}

double read_and_sum_from_input(int s)
{
	Vector v;
	vector_init(v,s);
	double sum = 0;
	
	for (int i = 0; i!=s; ++i)
	{
		cin>>v.elem[i];
		sum += v.elem[i];
	}
	return sum;
}

int main()
{
//	double d1 = 2.3;
//	double d2 {3.3};
//	complex <double> z = {1.1, 2.3};
//	int i2 = 7.2;	
//	auto b = true; // automatically initialize variable to the correct type.
//	print(i2);
//	if (b)
//	{
//		printf("%d\n", 1);
//	}
//	int i3 = 1;
//	printf("%d\n", i3);
//	++i3; //equivalent to i++;
//	printf("%d\n", i3);
//	++++i3;
//	printf("%d\n", i3);
//
//	printf("constants and constants expressions");
//	
//	const double dmv = 17.1;
//	//constexpr double sqdmv = square(dmv);
//	cout<< dmv << endl;
//
//
//	if (accept1())
//	{
//		printf("you have accepted!\n");
//	}
//
//	auto result = accept1();

//	if (result){
//		printf("you have accepted again!\n");
//	}else{
//	printf("It is a shame!\n");
//	}

	printf("below are for pointers\n");
	int v[6];
	int* p = &v[3]; // * denotes it is a pointer;
	// * denotes contents of, & denotes address of.
	// to access the value stored in the pointer, add * before the pointer, here *p;
	printf("\n");
//	for (int i = 0; i < 6; i++) {
//		v[i] = i+1;
//		printf("%d\n", v[i]);
//	}
//	int ap = *p;
//	cout<<"\n"<<ap<<" " <<*p<<endl;
//	
//	printf("\n");
//	for (auto& x : v){ // here & denotes reference to. 
//		x++;
//		printf("%d\n", x);
//	}
//	cout<<"\n"<<ap<<" " << *p <<endl;
//
//	for (auto x : v){ // here value of each element of v is pushed into x, the value of elements of v does not change. 
//		x++;
//		printf("%d\n", x);
//	}
//
//	std::cout<<std::endl;
//	for (int i = 0; i != 6; i++)
//	{
//	printf("v[%d]", i);
//	printf(" %d\n", v[i]);
//	}
//	

	/*printf("below are for verifying pointers: \n");
	cout << count_x(p, v[3])<<endl;
	*/

	
	Vector vec1;
	vector_init(vec1, 2);

	double temp = read_and_sum_from_input(2);
	printf("%f\n", temp);

}

