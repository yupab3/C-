#include <iostream>
#include <string.h>
using namespace std;

char*	MakeStrAdr(int len){
	// char*	str = (char *)malloc(sizeof(char)*len);
	char*	str = new char[len];
	return str;
}

int	main(void){
	char*	str = MakeStrAdr(20);
	strcpy(str, "strlen is 12");
	cout << str << '\n';
	// free(str);
	delete []str;
	return 0;
}
