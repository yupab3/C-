#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

typedef struct garbage{
	AForm*	data;
	struct garbage*	next;
}gc;

class Intern{
public:
	Intern(void);
	~Intern(void);

	AForm*	makeForm(const std::string _name, const std::string _target);
	AForm*	makeP(const std::string _target);
	AForm*	makeR(const std::string _target);
	AForm*	makeS(const std::string _target);
	void collectGarbage(AForm* data);
	void freeGarbage(void);

private:
	gc*	gc_head;
	static std::string	forms[3];
	static AForm*	(*Funcs[3])(const std::string _target);

	Intern(const Intern& _copy);
	Intern&	operator=(const Intern& _copy);
};

#endif
