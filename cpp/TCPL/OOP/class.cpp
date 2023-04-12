#include <iostream>
#include <stdio.h>
#include <vector>

typedef struct { // In c++, struct is a class whose members are public by default.
	int d,m,y;
	void init(int dd, int mm, int yy){
		this->d = dd;
		this->m = mm;
		this->y = yy;
	}
	void print(){
		printf("DAY: %d; MONTH: %d; YEAR: %d\n", this->d, this->m, this->y);
	}
} Date;

class Day{ 
private: // private member of the class can still be changed with address & pointer manipulation.
	// cpp protects private data by simply restricting the use of the  class member name.
	int day;
	int god;
public:
	void init(int dd, int gg){
		this->day = dd; 
		this->god = gg;
	}
	void print(){
		printf("DAY: %d; GOD: %d\n", day, god);			
	}
	int * dayhack(){
		return &day;
	}
};

struct DayHack{
	int day, god;
};

int main() {//int argc, char *argv[]
	
	Date birthday;
	birthday.print();
	birthday.init(1,2,3);
	birthday.print();

	Day monday;
	monday.init(1,2);
	monday.print();
	int * hack = monday.dayhack();
	(*hack)++; // The private member of the class is changed outside of the class.
	monday.print();
	((DayHack*)(&monday))->day=10; // Another way of changing the private member of the class through pointer casting.
	monday.print();
	return 0;
}
