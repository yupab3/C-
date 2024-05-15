#include "Form.hpp"

Form::Form(void):signGrade(0), executeGrade(0){
	// std::cout << "Form 생성자 호출\n";
}

Form::Form(const std::string &_name, const int _signGrade, const int _executeGrade): name(_name), approval(false), signGrade(_signGrade), executeGrade(_executeGrade){
	if (_signGrade < 1 || _executeGrade < 1){
		throw Form::GradeTooHighException("Too high - " + _name + "\n");
	}
	if (150 < _signGrade || 150 < _executeGrade){
		throw Form::GradeTooLowException("Too low - " + _name + "\n");
	}
}

Form::Form(const Form& _form): name(_form.name), approval(false), signGrade(_form.signGrade), executeGrade(_form.executeGrade){}

Form&	Form::operator=(const Form& _form){
	std::cout << _form << "어케 호출함?\n";
	return *this;
}

Form::~Form(void){}

Form::GradeTooHighException::GradeTooHighException(const std::string& _msg): std::logic_error(_msg){}

Form::GradeTooLowException::GradeTooLowException(const std::string& _msg): std::logic_error(_msg){}

const std::string& Form::getName(){
	return name;
}

const bool& Form::getApproval(){
	return approval;
}

const int& Form::getSignGrade(){
	return signGrade;
}

const int& Form::getExecuteGrade(){
	return executeGrade;
}

const std::string& Form::getName() const{
	return name;
}

const bool& Form::getApproval() const{
	return approval;
}

const int& Form::getSignGrade() const{
	return signGrade;
}

const int& Form::getExecuteGrade() const{
	return executeGrade;
}

void	Form::beSigned(const Bureaucrat& _bureaucrat){
	if (this->signGrade < _bureaucrat.getGrade()){
		throw Form::GradeTooLowException(_bureaucrat.getName() + "'s grade is lower than " + this->name + "'s signGrade\n");
	}
	this->approval = true;
}

std::ostream&	operator<<(std::ostream& _out, const Form& _form){
	_out << _form.getName() << ", Form approval " << std::boolalpha << _form.getApproval() << ", Form signGrade " << _form.getSignGrade() << ", Form executeGrade " << _form.getExecuteGrade() << '\n';
	return _out;
}
