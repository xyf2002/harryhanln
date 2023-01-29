#include <iostream>
using std::cout;

namespace aaa
{
int it = 1;
int itt = 2;
}

using namespace aaa;

int main(){
	cout<<"hi!"<<std::endl;
	cout<< itt<<std::endl;
	return 0;
}
