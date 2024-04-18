#include <iostream>
#include <iomanip>

int	main(void){
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << std::setw(11) << "str: " << &str << '\n';
	std::cout << std::setw(11) << "stringPTR: " << stringPTR << '\n';
	std::cout << std::setw(11) << "stringREF: " << &stringREF << '\n';
	std::cout << std::setw(11) << "str: " << str << '\n';
	std::cout << std::setw(11) << "stringPTR: " << *stringPTR << '\n';
	std::cout << std::setw(11) << "stringREF: " << stringREF << '\n';
	return 0;
}
