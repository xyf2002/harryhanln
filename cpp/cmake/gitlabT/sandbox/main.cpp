#include <iostream>
#include <functional>

int main() {

	std::cout<<"Hello, World!"<<std::endl;

	[out = std::ref(std::cout<<"Hello, ")](){out.get()<<"World!\n";}();
	return 0;
}
