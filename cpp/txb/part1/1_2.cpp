#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

void name(){
	cout<<"Please Enter Your First Name and age: \n";
	string fn; // The Definition, set aside memory for a variable.
	string sn;
	double age;
	double age2;
	cin >> fn >> sn; // first input is assigned to fn, second sn;
	string name = fn + ' ' + sn;
	cin >> age;
	age2 = age;
//	cout<<"Hello, "<< fn <<','<<"(age "<<age<<")!\n"; // Note char is surrounded by ' '
	printf("Hello ");
	cout<<name;
	printf(" %2.0f months old!\n", age2*12);
}

int main(){
//	name();
	char c = 'x';
	int i1 = c;
	cout<<c<<' '<<i1<<endl; // 'x' is usually assigned as 120 in ASCII

	int a = 100;
	char c1 = a;
	int b = c1;
	c = a;

	cout<<a<<b<<c1<<c<<endl;

	const double pi = 3.1415926;
	// const means pi can not be changed after assignment.
// Selecting: if and Switch
// Note "break" is required
// Each statement is ended with break.
// The value for switch can not be string. 
// To switch strinig, use if or map.
// switch usually will result in more efficient machine code after compilation.

	cout<<"The followings are for switch\n";

	switch (a){
	case 50:
		cout<<"a==50z\n";
		break;
	case 100:
		cout<<"a==100\n";
		break;
	default:
		cout<<"N/A\n";
	}
	

	return 0;
}
