#include <stdio.h>
#include <unistd.h>  // read() write() etc
#include <fcntl.h>  // open()
#include <errno.h>

int main(){
	int word;
	// STDIN is always open 
	
	ssize_t nr = read(STDIN_FILENO, &word, 2*sizeof(char));
	printf("word: %c\n", word);
	return 0;
}
