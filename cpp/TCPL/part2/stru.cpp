#include <iostream>

// a structure is a aggregate of elements of arbitrary type.
struct Address{
	const char* name;
	int number;
	const char* street;
	const char* town;
	char state[2];
	const char* zip;
}; // note the terminating semicolon

int main(){
	Address jd = {
		"Jimmy",
		61, "South St",
		"New Providence",
	{'N', 'J'}, "07974"
	};
	// the struct Address jd is initialized with order.
	
	// struct is accessed through pointer using the -> (struct pointer dereference) operator.
	Address* p = &jd;
	std::cout<<p->name<<std::endl;
	std::cout<<(*p).name<<std::endl;
	return 0;
}
