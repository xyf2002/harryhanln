#include <iostream>
#include <stdio.h>
#include <vector>

#define PRINTER(name) printer(#name, (name)) // Utilize c preprocessor

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
public:
	static void set_default(int dd, int gg){
		Day::default_day.day=dd;
		Day::default_day.god=gg;
	}
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
	// Constructors: if the class has a construtor, all dec
	Day(){}; // Default constructor; When using def
	void ppp();
	Day(int,int);
	Day(int dd){this->day = dd;}; // Constructors can overload;
	void expose_address(){
		std::cout<<this<<std::endl;
	}
private: // private member of the class can still be changed with address & pointer manipulation.
	// cpp protects private data by simply restricting the use of the  class member name.
	int day = 2; // can set default value
	int god;
	static Day default_day; // static member of the class: similar to java's static
};

Day::Day(int dd, int gg){ // Defining a constructor outside of the class. Note the constructor must be declared in the class.
	this->day=dd;
	this->god=gg;
}

void Day::ppp(){ // defining a method for the class out side of the class. The method must be declared in the class. 
	std::cout<<"aa\n";
}

void printer(const char * str, Day day){
	printf("class Day: %s ", str);
	day.print();
}

struct DayHack{
	int day, god;
};

int main() {//int argc, char *argv[]
	
	Date birthday;
	birthday.print();
	birthday.init(1,2,3);
	birthday.print();

	Day monday; // use default constructor. Note, there is no parenthesis
	monday.init(1,2);
	printf("monday: ");
	monday.print();
	int * hack = monday.dayhack();
	(*hack)++; // The private member of the class is changed outside of the class.
	monday.print();
	((DayHack*)(&monday))->day=10; // Another way of changing the private member of the class through pointer casting.
	monday.print();

	Day Tuesday(33); // use constructor. How to use a constructor
	Tuesday.expose_address();
	PRINTER(Tuesday);
	Tuesday = Day(22);
	Tuesday.expose_address();
	PRINTER(Tuesday);

	Day ttt;
	PRINTER(ttt);
	
	return 0;
}
