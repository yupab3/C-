#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void){
	std::srand(std::time(NULL));
	try{
		Bureaucrat	human("sungyoon", 1);
		std::cout << human;
		Bureaucrat	human1("dongyeuk", 3);
		std::cout << human1;
		Bureaucrat	human2("jaejilee", 5);
		std::cout << human2;
		ShrubberyCreationForm		form1("form1");
		RobotomyRequestForm		form2("form2");
		RobotomyRequestForm		form3("form3");
		PresidentialPardonForm	form4("form4");
		std::cout << form1;
		human1.signForm(form1);
		human1.executeForm(form1);
		human1.executeForm(form2);
		std::cout << form2;
		human2.signForm(form2);
		human2.executeForm(form2);
		std::cout << form3;
		human2.signForm(form3);
		human2.executeForm(form3);
		std::cout << form4;
		human2.signForm(form4);
		human2.executeForm(form4);
		human2.downGrade();
		human.signForm(form1);
		human.signForm(form2);
		human.signForm(form3);
		human1.signForm(form1);
		human1.signForm(form2);
		human1.signForm(form3);
		human2.signForm(form1);
		human2.signForm(form2);
		human2.signForm(form3);
		form4.execute(human2);
		human2.signForm(form1);
		human2.signForm(form2);
		human2.signForm(form3);
	}
	catch(std::exception &e){
		std::cout << e.what();
	}
	return 0;
}
