#include "Bureaucrat.hpp"

int	main(void){
	try{
		Bureaucrat	human("sungyoon", 1);
		std::cout << human;
		Bureaucrat	human1("dongyeuk", 3);
		std::cout << human1;
		Bureaucrat	human2("jaejilee", 5);
		std::cout << human2;
		Form		form1("form1", 1, 3);
		std::cout << form1;
		Form		form2("form2", 3, 5);
		std::cout << form2;
		Form		form3("form3", 5, 7);
		std::cout << form3;
		human.signForm(form1);
		human.signForm(form2);
		human.signForm(form3);
		human1.signForm(form1);
		human1.signForm(form2);
		human1.signForm(form3);
		human2.signForm(form1);
		human2.signForm(form2);
		human2.signForm(form3);
	}
	catch(std::exception &e){
		std::cout << e.what();
	}
	return 0;
}
