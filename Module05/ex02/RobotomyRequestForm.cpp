#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm("", 0, 0){
	// std::cout << "Form 생성자 호출\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target): AForm("RobotomyRequestForm", 72, 45){
	target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _copy): AForm(_copy.getName(), _copy.getSignGrade(), _copy.getExecuteGrade()){
	target = _copy.target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& _form){
	std::cout << _form << "어케 호출함?\n";
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm::FileError::FileError(const std::string& _msg): std::logic_error(_msg){}

void	RobotomyRequestForm::action(void) const{
	std::cout << "DRRRRRRRRRRR!!!... " << '\n';
	if (rand() % 2 == 1){
		std::cout << target << " has been robotomized!!" << '\n';
	}
	else{
		std::cout << "robotization of " << target << " has failed.." << '\n';
	}
}

const std::string&	RobotomyRequestForm::getTarget(void) const{
	return target;
}

std::ostream&	operator<<(std::ostream& _out, const RobotomyRequestForm& _form){
	_out << _form.getName() << ", Form approval " << std::boolalpha << _form.getApproval() << ", Form signGrade " << _form.getSignGrade() << ", Form executeGrade " << _form.getExecuteGrade() << ", Target " << _form.getTarget() << '\n';
	return _out;
}
