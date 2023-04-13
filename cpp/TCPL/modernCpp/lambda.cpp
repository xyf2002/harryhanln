#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <typeinfo>

int main() {//int argc, char *argv[]
	/*
	 * []() mutable -> T { } 
	 * //T is the return type, still lacking throw()
	 * [] capture:
	 * [x] by value,
	 * [&x] by reference
	 * [=] all by value
	 * [&] all by reference
	 * mix and match [a,b]
	 * */
	auto sc = [](double x){return sin(x)+cos(x);};

	auto returnType= [](double x, double y)->double {return sin(x)+cos(x)-y;};
	std::cout<<sc(0.3)<<std::endl; // Use lambda
	std::cout<<returnType(0.3, 3)<<std::endl;
	auto imm = [](double x){return 2*x;};

	// capture
	std::string astring = "This is astring!"; // cpp string can not be printed with printf;
	std::cout<<astring<<std::endl;
	astring+= " appended!"; // += is to append to string
	std::cout<<astring<<std::endl;
	auto appendStr = [&astring] (std::string addendum){astring+=addendum; return;}; // Recall in ANSI there is no pass by reference.
	appendStr("aaa");
	std::cout<<astring<<std::endl;
	return 0;
}
