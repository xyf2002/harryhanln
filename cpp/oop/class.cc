#include <iostream>
#include <stdio.h>
#include <vector>

#define PRINTER(name) printer(#name, (name)) // Utilize c preprocessor

struct Die{
	int a,b,c;
};

typedef struct { // In c++, struct is a class whose members are public by default.
	int d,m,y;
	void init(int dd, int mm, int yy){
		this->d = dd;
		this->m = mm;
		this->y = yy;
	}
	void print(){
		printf("DAY: %d; MONTH: %d; YEAR: %d\n", this->d, this->m, this->y); // In ANSI C, no funciton or method can be defined, declared, or associated directly with struct. i.e, defining or declaring an function inside struct will produce error.
	}
} Date;

class Day{ 
public:
	int get_day() const{ // This is the constant member function: the constant key word means this function can not modify the value of the class.
		return this->day; 
	}
	static void set_default(int dd, int gg){ // All methods of classes are inline functions by default.
		// inline signle to the compiler such function shall be expanded at compile time.
		Day::default_day.day=dd;
		Day::default_day.god=gg;
	}
	Day& init(int dd, int gg){
		this->day = dd; 
		this->god = gg;
		return *this;
	}
	Day& print(){ // return its reference so that it can be chained.
		printf("DAY: %d; GOD: %d; GODDESS: %d\n", day, god, goddess);	
		return *this;
	}
	int* dayhack(){
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
	Day& add_day(){
		this->day++;
		return *this;
	}
	int get_day(){
		return day;
	}
	Day& set_goddess(int in){
		goddess=in;
		return *this;
	}
	Day& add_goddess(){
		(goddess=1);
		return *this;
	}
	mutable int goddess; //mutable member can be changed even if the object is declared const.
private: // private member of the class can still be changed with address & pointer manipulation.
	// cpp protects private data by simply restricting the use of the  class member name.
	int day = 2; // can set default value
	int god;
	static Day default_day; // static member of the class: similar to java's static
};

Day Day::default_day; // Declare global static variable default_day.

inline Day::Day(int dd, int gg){ // Defining a constructor outside of the class. Note the constructor must be declared in the class.
	this->day=dd;
	this->god=gg;
}

inline void Day::ppp(){ // defining a method for the class out side of the class. The method must be declared in the class. 
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

	// use default constructor. Note, there is no parenthesis
	Day monday; 
	monday.init(1,2);
	printf("monday: ");
	monday.print();
	// change private member of the class with "techniques"
	int * hack = monday.dayhack();
	(*hack)++; // The private member of the class is changed outside of the class.
	monday.print();
	((DayHack*)(&monday))->day=10; // Another way of changing the private member of the class through pointer casting.
	monday.print();

	// use constructor. How to use a constructor
	Day Tuesday(33); 
	Tuesday.expose_address();
	PRINTER(Tuesday);
	Tuesday = Day(22);
	Tuesday.expose_address();
	PRINTER(Tuesday);

	// Initialization by copying
	Day ttt=Tuesday; 
	PRINTER(ttt);
	std::cout<<"chained"<<std::endl;
	ttt.print().expose_address();

	Day::set_default(1,2);
	
	Die a; //delcare a Die date type with name a. Not Compatible in ANSI C, which requires declaration like struct Die a.
	
	const Day Friday(33,22);
	PRINTER(Friday);
	Friday.goddess=1;
	PRINTER(Friday);
	Friday.set_goddess(1);
	return 0;
}
