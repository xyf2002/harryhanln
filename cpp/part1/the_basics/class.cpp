#include <stdio.h>
#include <iostream>
//#include "Vector.h"
using namespace std;


class Vector{
	public:
		Vector(int s) :elem{new double[s]}, sz{s} {} // recall a{b} is a = b; it is like a java constructor.
		// constructors is a "function" with the same name to the class. 
		double& operator[](int i){if (i<0 || size()<=i) throw out_of_range{"Vector::operator[]"}; return elem[i];} // exceptions are thrown at run time, not compile time.
		int size() {return sz;}
	private:
		double* elem; // elem is a pointer to a double array.
		int sz;
}; // notice the final ;

double read_and_sum(int s)
{
	Vector vec(s);
	for (int i = 0; i != vec.size(); ++i){
		cin >> vec[i];
	}

	double sum = 0;
	for (int i = 0; i != vec.size(); ++i){
		sum += vec[i];
	}
	return sum;
}


// enumerators

enum class Color {red, yellow , green};

Color operator++(Color t) // prefix increment ++
{
	switch(t){
	case Color::red:	return Color::green;
	case Color::yellow:	return Color::red;
	case Color::green:	return Color::yellow;
	}
	return Color::yellow;
}


int main(){
	Vector v(6); // declares a vector of with sz 6 and elem which is a pointer to array of 6 doubles.
	
	cout<<"numbers of integers to add: "<<endl;
	int a = 0;
	cin >> a;

	double res = read_and_sum(a);

	cout << res << endl;

	return 0;
}
