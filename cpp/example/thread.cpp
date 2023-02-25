#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "conio.h"

void pline(char a){
	while(1){
		std::cout<<a<<std::endl;
		// std::this_thread::sleep_for(std::chrono::microseconds(100000));
		sleep(1);
	}
}

void key(){
	while(1){
		int kval = getch();
		std::cout<<"Key Pressed!"<<kval<<std::endl;
	}
}

void pt(int a){
	while (a --> 0) printf("a: %d\n", a);
	// std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout<<"finished!\n";
}

int main(){
	// std::thread t1(pline, 'a'); //Create a thread, can call function, function pointer, or lambda. Input of the function is separated by the comma.
	// std::thread t2(key);

	// t1.join(); // main thread wait for the thread to finish.
	// t2.join();
	
	std::thread t3(pt, 6);
	printf("main\n");

	if (t3.joinable()){
		t3.detach(); // Detach the thread from main thread. i.e., if the thread has not finished execution when main thread's execution is finished, it will not be executed. This may cause inconsistent performance as the time for execution is definite.
	}
	// t3.join(); // wait for the thread to complete.
	// if (t3.joinable()){ // Good practice, apply joinalbe before the program is joined.
	// 	t3.join(); // double join of the same thread cause the program to terminate
	// }
	printf("main after\n");
	return 0;
	//ssss
}
