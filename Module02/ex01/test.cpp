#include <iostream>

int	main(void){
	int	a = -42;
	std::cout << a << '\n';
	a << 8;
	std::cout << a << '\n';
	a >> 8;
	std::cout << a << '\n';
}