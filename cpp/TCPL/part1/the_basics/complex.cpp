#include <iostream>
#include <stdio.h>

class complex{
	double re, im;
public:
	// First define three constructors
	complex(double r, double i): re {r}, im {i} {}
	complex(double r): re {r}, im {0} {}
	complex(): re{0}, im{0} {}
	// Getters and Setters
	double real() const {return re;}
	void real(double d) {re=d;}
	double imag() const {return im;}
	void imag(double d) {im = d;}

	complex& operator += (complex z) {re+=z.re, im+=z.im; return *this;}
	complex& operator -= (complex z) {re-=z.re, im-=z.im; return *this;}

	complex& operator *=(complex);
	complex& operator /=(complex);
	
	void prcom (){printf("(%4.2f,%4.2f)\n",re, im);}
	//%4.2 means 4 spaces in total (including the decimal), and 2 digits after the decimal point.

};

int main()
{
	complex a {2.8888888, 1.8888888};	
	std::cout<<a.real()<<std::endl;
	a.prcom();

	return 0;
}
