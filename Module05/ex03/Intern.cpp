#include "Intern.hpp"

std::string	Intern::forms[3] = {
	"robotomy request",
	"shrubbery creation",
	"presidential pardon"
};

AForm*	(Intern::*funcs[3])(const std::string _target) = {
	&Intern::makeR,
	&Intern::makeS,
	&Intern::makeP
};

Intern::Intern(void){
	gc_head = NULL;
}

Intern::~Intern(void){
	gc* tmp = gc_head;
	while (tmp != NULL){
		tmp = gc_head->next;
		delete gc_head->data;
		delete gc_head;
		gc_head = tmp;
	}
}

void Intern::collectGarbage(AForm* _data){
	gc*	tmp = new gc;
	tmp->data = _data;
	tmp->next = gc_head;
	gc_head = tmp;
}

void Intern::freeGarbage(void){
	gc* tmp = gc_head;
	while (tmp != NULL){
		tmp = gc_head->next;
		delete gc_head->data;
		delete gc_head;
		gc_head = tmp;
	}
}

AForm*	Intern::makeForm(const std::string _name, const std::string _target){
	for (int idx = 0; idx < 3; idx++){
		if (this->forms[idx] == _name){
			collectGarbage((this->*funcs[idx])(_target));
			return gc_head->data;
		}
	}
	return NULL;
}

AForm*	Intern::makeP(const std::string _target){
	std::cout << "Intern creates PresidentialPardonForm\n";
	return new PresidentialPardonForm(_target);
}

AForm*	Intern::makeR(const std::string _target){
	std::cout << "Intern creates RobotomyRequestForm\n";
	return new RobotomyRequestForm(_target);
}

AForm*	Intern::makeS(const std::string _target){
	std::cout << "Intern creates ShrubberyCreationForm\n";
	return new ShrubberyCreationForm(_target);
}


