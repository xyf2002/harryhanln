#include <iostream>
#include <typeinfo>

int main(){
	std::string astr = "helloiterator!";
	std::cout<<astr<<std::endl;
	auto it = astr.begin();
	std::cout<<typeid(it).name()<<std::endl; //typeid(variable).name() returns type)
	std::cout<<typeid(astr).name()<<std::endl;
	int a = 1;
	std::cout<<typeid(a).name()<<std::endl;
	while (it!=astr.end()){
		*it = toupper(*it);
		++it;
	}
	std::cout<<astr<<std::endl;
	return 0;
}
