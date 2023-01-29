#include <iostream>
#include <vector>

void printv(std::vector<int> ivec){
	auto ite = ivec.begin();
	for (int i=0; i!=3; ++i){
		std::cout<<*ite<<std::endl;
		ite++;
	}
	std::cout<<"\n";
}
int main(){
	std::vector <int> ivec {1,2,3};
	printv(ivec);
	for (int i=0; i!=3; ++i){
		++ivec[i];
	}
	printv(ivec);
	for (auto &i: ivec) {
		++i;
	}
	printv(ivec);
	auto ite = ivec.begin();
	for (int i=0; i!=3; ++i){
		(*ite)++; //This is equivalent to *ite = *ite + 1; but not *ite++.
		ite++;
	}
	printv(ivec);
	return 0;
}
