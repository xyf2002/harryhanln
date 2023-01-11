#include <stdio.h>
#include <cstdint>
#include <limits>
#include <iostream>
using namespace std;

int x = 10000;

int main(){
	cout << "size of long is: "<<sizeof(1L)<<endl;
	cout << "size of long long is: "<<sizeof(1LL)<<endl;
	
	cout << "the largest float: " <<std::numeric_limits<float>::max()<<endl;
	cout << "the largest int: " <<std::numeric_limits<int>::max()<<endl;
	cout << "char is signed: " <<std::numeric_limits<char>::is_signed << endl;

	// Certain machine architectures needs also alignment for accessing data
	
	auto ac = alignof('c');
	cout <<"alignment of \'c\' is: "<< ac << endl;

	auto ai = alignof(1);
	cout <<"alignment of \'1\' is: "<< ai << endl;

	// declarations
	
	const char* name = "Njal"; 
	// set aside memory for a pointer to char
	// set aside memory for string literals "Njal"
	// initialize the pointer with the address of that string literal
	cout << name << endl;
	
	const char na[] = "Njal";
	const string sna = "Njal";

	cout << na[1]<<endl;
	cout << sna[1] <<endl;
	
	// The Structure of declaration
	// 1. prefix specifier (`static` or `virtual` or `constexpr`)
	// 2. base type (vector<double> or const int)
	// 3. declarator optionally including the name (p[7] pr *(*)[])
	// 4. optional suffix (const or noexcept)
	// 5. optional initialiser followed by =
	// A variable can only be defined once.
	
	// recall const means "final" in java
	// constempr is evaluated at compile time.

	// *, *consy, &, && are prefix of declarator
	// [], (), -> are suffix

	const int x = 1, y = 2; // const int x, const int y
	int* p, pp; //int* p, int pp;
	int b, *bb; //int b, int* bb
	int v[10], *pv; // int v[10], int *pv
	int *c;

	// Names
	// a name (or identifier) starts is a sequence of letter and numerals. It must start with a letter, _ is considered a letter.
	// It shall not include special signs such as *(&^%
	
	/*
	Scope of the variable
	A variable declared in a certain scope can only be referenced and modified in the same scope
	Local scope: those in a function or statement (such as for)
	Class scope
	namespace scope
	global scope
	*/
	
	cout<<"Local scope x = " <<x<<endl;
	cout<<"global scope x = " <<::x<<endl; // use :: to access global scope variable.

	{
		int x = 2;
		cout << "second local scope x = " << x <<endl;
	}
	
	// Initialization
	// Initialization can use one of the four following syntax style
	{
		int a1 {1}; // the recommended initialization. It is new in C++11 
		int a2 = {2 }; // used in C
		int a3 = 3; // used in C
		int a4(4);
		printf("%d %d %d %d", a1, a2, a3, a4);
	}



}
