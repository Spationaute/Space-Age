#include <stdio.h>

int main(int args,char* argv[]){
	//a space is an empty space 
	char empty=' ';
        
	//a dièse(#) is an ground space
	char ground='#';
	
	//a zero(0) is an landing/takeoff space
	char land='0';

	//1 to 9 is an entity from the list
	//A to E is an message in the list

	FILE* toRead=fopen(argv[1],"r");
	
	
	return 0;
}
