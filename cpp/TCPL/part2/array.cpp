#include <iostream>
#include <stdio.h>

void p2da (int* m, int dim1, int dim2){
	for (int i=0; i!=dim1; ++i){
		for (int j=0; j!=dim2;++j){
			std::cout<<m[i*dim2+j]<<" ";
		}
		std::cout<<std::endl;	
	}
}
int main(){
	char sar[] = "He!";
	for (int i=0; sar[i]!=0; i++){
		std::cout<<sar[i]<<std::endl;
	}

	std::cout<<"\naccess by pointers! \n\n";

	for (char* p = sar; *p!=0; ++p){ // recall the last element of the char arrary by default is \0
		std::cout<<*p<<std::endl;
	}
	
	std::cout<<std::endl;
	char* pp = sar;
	std::cout<<*pp<<" "<<*(pp+1)<<std::endl;	
	
	// Mind for build in arrays (char, int float, etc): sar[1] == *(&sar[0]+1)== *(sar+i) == *(i+sar) = 1[sar]
	
	std::cout<<sar[1] <<" "<<1[sar]<<std::endl; // this does not holds true for vectors, arrays, and other standard-library containers.
	
	// for pointer p, (p+1) points to the the next element in the array, p-1 the previous one. etc.
	
	//multidimensional arrays is interpretated as a single dimensional array.
	
	int ma [3][5];
	for (int i=0; i!=3; ++i){
		for (int j=0; j!=5; ++j){
			ma[i][j] = 10*i+j;
			std::cout<<ma[i][j]<<j[i[ma]]<<" "; //ma[i,j] does not work. , is the sequencing operator.
		}
		std::cout<<std::endl;
	}

	// passing arrays by pointers
	p2da(ma[0], 3, 5);

	//pointers and constants
	
	{
		char s[] = "worms";
		char* p = s;
		p[4]='2';
		std::cout<<s<<std::endl; // recall s is char* s[0]. it is automatically transferred to the whole array
		std::cout<<*p<<std::endl; // recall s is char* s[0]. it is automatically transferred to the whole array
		p = s+1;
		std::cout<<*p<<std::endl;

		const char* cp = s; // this expression set the array to be immutable: read it from right to left: cp is pointer to char const
		char* const ccp = s; // this expression set the pointer to be immutable: ccp is const pointer to char

	}
	return 0;
}
