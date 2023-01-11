#include<iostream>


void rinc(int& a){
	++a;
}

void inc(int a){
	++a;
}

int next(int a){
	return ++a;
}
int main(){
	{
		// Pointer: pass large amount of data at low cost
		int int1 = 10;
		int* p1 = &int1;
		std::cout<<int1<<std::endl;
		std::cout<<p1<<std::endl;
		std::cout<<&int1<<std::endl;
		std::cout<<*p1<<std::endl;
		std::cout<<&p1<<std::endl;
		// referenc: access the reference with exactly the same syntax as the name of the object
		// a reference always refer to the object it initialized
		// there is no nullreference
		// does not impose performance overhead compared to pointers.
	}
	{
		// reference must always be initialized to refer to an object.
		// all operators that 'apply' to a references actually applies to the object the reference refers to. The reference itself can not be changed.
		// reference can be regarded as constant pointer that is dereferenced each time it is used. 
		// It can not be manipulated
		std::cout<<"Example for Reference\n";
		int var {1}; 
		int& r {var}; // r and var now refers to the same int.
		int x = r; // a new int, named x, is now set to be equal to current value of var.
		int* pv = &var;
		int* pr = &r;

		std::cout<<var<<std::endl;
		std::cout<<r<<std::endl;
		std::cout<<x<<std::endl;

		r = 2; // r = var = 2;
		std::cout<<var<<std::endl;
		std::cout<<r<<std::endl;
		std::cout<<x<<std::endl;

		var = 3; // r = var = 3;
		std::cout<<var<<std::endl;
		std::cout<<r<<std::endl;
		std::cout<<x<<std::endl;

		std::cout<<"*(&var)=5"<<std::endl;
		*pv = 5;
		std::cout<<var<<std::endl;
		std::cout<<r<<std::endl;
		std::cout<<x<<std::endl;

	}

	{
		std::cout<<"Testing functions and reference\n";
		int a = 1;
		int ra = 1;
		std::cout<<"a: "<<a<<" ra: "<<ra<<std::endl;
		inc(a); rinc(ra);
		std::cout<<"a: "<<a<<" ra: "<<ra<<std::endl;
	}
	
	{
		// lvalue and rvalue
		// lvalue are values with a specific memory address, rvalue are temporary values without an address
		std::string var {"edinburgh"};
		std::string& r1 {var}; // lvalue reference
		std::string&& rr3 {"Oxford"}; //rvalue reference
	}

	{
		// pointer and references are two mechanisms for referring to an object without copying it.
	}
}
