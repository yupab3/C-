#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("", 0, 0){
	// std::cout << "Form 생성자 호출\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target): AForm("PresidentialPardonForm", 25, 5){
	target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _copy): AForm(_copy.getName(), _copy.getSignGrade(), _copy.getExecuteGrade()){
	target = _copy.target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& _form){
	std::cout << _form << "어케 호출함?\n";
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void){}

void	PresidentialPardonForm::action(void) const{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}

const std::string&	PresidentialPardonForm::getTarget(void) const{
	return target;
}

std::ostream&	operator<<(std::ostream& _out, const PresidentialPardonForm& _form){
	_out << _form.getName() << ", Form approval " << std::boolalpha << _form.getApproval() << ", Form signGrade " << _form.getSignGrade() << ", Form executeGrade " << _form.getExecuteGrade() << ", Target " << _form.getTarget() << '\n';
	return _out;
}
