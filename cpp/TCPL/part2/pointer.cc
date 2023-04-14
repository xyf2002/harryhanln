#include <iostream>
#include <vector>
#include <string.h>

int main(){
	int a = 10; // a is a integer, declared by (int)
	int* b = &a; // b is a pointer to integer, declared by (int*). It points to the reference of a.
	// & is the "address of operator." b holds the address of a.
	
	int c = *b; // now c == a. *is the dereference operator. 
	
	std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;
	std::cout<<c<<std::endl;

	{
		int* pi; // pointer to int
		char** ppc; // pointer to a pointer to char
		int* ap[15]; // array of 15 pointer to ints
		int (*ft)(char*); // pointer to a function taking a char* argument and returns a int
		int* f(char*); // a function taking in char* argument and returns a pointers.
		int* nulp = nullptr; // the null pointer
	}

	{	
		// String Literals	
		std::cout<<"size of \"Bohr\" is: "<<sizeof("Bohr")<<std::endl; // string literals are termianted by the null character "\0"
		// the type of string literals is "array of appropriate number of const characters"
		std::string Bohr {"Bohr"};
		const char Bar[5] {'B', 'o', 'h', 'r', '\0'}; // Bar and Bohr are equivalent.
		std::cout << Bohr << " "<< Bar<<std::endl;
		
		std::cout<<"\nTo modify a string literal\n";
		char p[] = "Zero";
		std::cout<< p <<std::endl;
		p[0] = 'X';
		std::cout<< p <<std::endl;

		//  "" must appear on the same line. However, the following is permited:
		char alpha[] = 
		"aaaa"
		"bbbb\a";
		std::cout<< alpha<<std::endl;

		// Raw String Literals

		std::string rawstring = R"(\""£$4)"; // Raw strings are declared as R"(ccc)". In this way, all the letters between () are taken literally. Raw string can contain new line.
		// How to use ()?
		std::string bra = {R"****("quoted
		with ()")****"
		};

		std::cout<< rawstring << std::endl;
		std::cout<< bra<< std::endl;
	}	
//pointer and arrays
	{
		std::cout<<"The following are for pointers and arrays\n";
		int v[] = {1,2,3,4};
		int* p = v; // p and pp are equivalent. Implicit conversion of an arry name to a pointer to the initial element of the arrya.
		
		int* pp = &v[0];
		int* p3 = v+1; // p3 and pp3 are equivalent.
		int* pp3 = &v[1];

		std::cout<<*p<<" "<<*pp<<std::endl;
		std::cout<<*p3<<" "<<*pp3<<std::endl;
	}

	{
		char v[] = "Annemarie";
		char* p = &v[0];
		std::cout<<strlen(p)<<std::endl;
		std::cout<<p<<std::endl;
		std::cout<<strlen(v)<<std::endl;
	}
}

// Arrays
float v[3]; // an array of 3 floats.
char* a[32]; // an array of 32 pointers to char.

void f(int a){
	int aa [10] = {1,2,3,4}; // assume all the rest are 0s
	// can not initialize an array with another.
	aa[6] = 9;
	// int aaa [a]; not allowed: array bound must be a constant expression
	std::vector<int> v2(a); // allowed, bound of vector can be variable
	
}



