#include <iostream>
#include <vector>

// a structure is a aggregate of elements of arbitrary type.
struct Address{
	const char* name;
	int number;
	const char* street;
	std::string town;
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
	{
		struct Readout{
			std::string hour;
			int value;
			char seq;
		}; // member are allocated in memory in declaration order.
		
		Readout a{
			"ab", 24, 'b'
		};
		Readout* p = &a;
		std::cout<<(*(p)).hour<<std::endl;
	}
	{
		struct List;
		struct Link{
			Link* pre;
			Link* suc;
			List* member_of;
			int data;
		};
		struct List{
			Link* head;
		};
	}
	// struct is simply a class where the member are public by default. It can have member functions, and constructors.
	{
		struct Point{
			std::vector<int> p1;
			Point(int a) {p1.push_back(a);p1.push_back(0);p1.push_back(0);}
			Point(int a, int b){p1.push_back(a);p1.push_back(b);p1.push_back(0);}
			Point(int a, int b, int c){p1.push_back(a);p1.push_back(b);p1.push_back(c);}
			void print() {for (int i=0; i!=3; i++){std::cout<<p1[i]<<" ";} std::cout<<"\n";}
		};
		Point p1 {1,2,3};
		Point p2 {2,3};
		p1.print();
		struct Points{
			std::vector<Point> elem;
		};

	}
	// Struct and array
	{	
		struct Point{
			int x,y;
		};

		Point points[3] {{1,2}, {1,3}, {2,3}};
		int x2=points[2].x;
	}

	return 0;
}
