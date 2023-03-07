// #include <stdio.h>
// #include <cstring>

bool readFile(const char * filename, char * allocation){
	FILE *fp = fopen(filename, "r");
	if (!fp) return 0;
	char res[8096];
	char buffer[1024];
	while (fgets(buffer, 1024, fp)!=NULL){
		strcat(res, buffer);
	}
	for (int i = 0; i < 8096; i++){
		allocation[i]=res[i];
	}
	allocation[strlen(allocation)-1]='\0'; // Remove the last character of the string.
	return 1;
}

// int main() {//int argc, char *argv[]
// 	char * aaa = new char [100000];
// 	readFile("mytext.txt", aaa);	
// 	delete[] aaa;
//
// 	return 0;
// }
