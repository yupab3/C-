#include <iostream>

int	exceptionFunc(void){
	try{
		int	a = 1;
		throw a;
	}
}

int	main(){
	exceptionFunc();
	catch(int expn){
		return ;
	}
}