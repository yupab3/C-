#include "Bureaucrat.hpp"

int	main(void){
	try{
		Bureaucrat	human("sungyoon", 1);
		std::cout << human;
		Bureaucrat	human1("dongyeuk", 0);
		std::cout << human1;
		Bureaucrat	human2("jaejilee", 151);
		std::cout << human2;
	}
	catch(std::exception &e){
		std::cout << e.what();
	}
	// catch(Bureaucrat::GradeTooHighException _e){
	// 	std::cout << _e.what() << '\n';
	// }
	// catch(Bureaucrat::GradeTooLowException _e){
	// 	std::cout << _e.what() << '\n';
	// }
	return 0;
}
