#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>

long ctime(){
	auto now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::nanoseconds>(epoch);
	long duration = value.count();
	return duration;
}

int main(){
	int ls [1000];	
	for (int i=0; i!=1000; ++i){
		ls[i] = ((ctime()%1871)+17)*((ctime()%97)+29);
	}
	for (auto i:ls){
		std::cout<<i<<std::endl;
	}
	std::ofstream myfile;
	myfile.open("randnum.txt");
	for (auto i:ls){
		myfile << i<<std::endl;
	}
	myfile.close();

	for(int i=0; i!=100; ++i){
		std::cout<<std::endl;
	}

	std::ifstream opfi("randnum.txt");

	std::string buf;
	int bufi;
	int cot {0};
	while(std::getline(opfi, buf)){
		bufi = stoi(buf); //convert string to int
		std::cout<<cot<<"   "<<bufi<<std::endl;
		cot++;
	}
	opfi.close();
	
	return 0;
}
