#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "conio.h"
#include <mutex>

int a {0};

std::mutex m;

void adda(){
	m.lock(); //use mutex to lock the variable so that only one thread can access it at one time.
	for (int i=0; i<50; ++i){
		++a;
		std::cout<<"a:"<<a<<std::endl;
	}
	m.unlock();
}

// try_lock attempts to lock the mutex, returns immediately.
// If it locked successfully, it returns true.

void tryadda(){
	for (int i=0; i<5000; ++i){ 
		if (m.try_lock()){ // Note, multiple thread accessing the try lock may get inconsistent results.
			++a;
			// std::cout<<"a:"<<a<<std::endl;
			m.unlock();
		}
	}
}

int main(){
	a = 0;

	std::thread t1(tryadda);
	std::thread t2(tryadda);

	t1.join();
	t2.join();


	std::cout<<a<<std::endl;

	return 0;
}
