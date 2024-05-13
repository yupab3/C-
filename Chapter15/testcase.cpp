#include <iostream>

int	main(void){
	try{
		int *value = new int;
		*value = 1;
		std::cout << value << ", " << (char)*value << std::endl;
		// int	*value2 = new int;
		throw std::runtime_error("test");
	}
	catch(char&	expn){
		std::cout << &expn << ", " << (char)(expn + 64);
		// delete expn;
	}
}



// #include <iostream>

// void	asd(void){
// 	system("leaks a.out");
// }

// int	main(){
// 	try{
// 		int *value = new int;
// 		*value = 1;
// 		std::cout << value << ", " << (char)*value << std::endl;
// 		// int	*value2 = new int;
// 		throw (char)*value;
// 	}
// 	catch(char&	expn){
// 		std::cout << &expn << ", " << (char)(expn + 64);
// 		// delete expn;
// 	}
// 	atexit(asd);
// }