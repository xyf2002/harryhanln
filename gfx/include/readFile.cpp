// #include <string>
// #include <iostream>
// #include <fstream>


bool readFile(const char* pFileName, std::string& outFile){
	std::ifstream f(pFileName);

	bool ret = false;

	if (f.is_open()){
		std::string line;
		while(getline(f, line)){
			outFile.append(line);
			outFile.append("\n");
		}
		f.close();
		ret = true;
	}
	return ret;
}

// int main(){
// 	std::string a;
// 	readFile("a.txt", a);
// 	std::cout<<a<<std::endl;
// }
