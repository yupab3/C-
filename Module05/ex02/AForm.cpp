#include "AForm.hpp"

AForm::AForm(void):signGrade(0), executeGrade(0){
	// std::cout << "Form 생성자 호출\n";
}

AForm::AForm(const std::string &_name, const int _signGrade, const int _executeGrade): name(_name), approval(false), signGrade(_signGrade), executeGrade(_executeGrade){
	if (_signGrade < 1 || _executeGrade < 1){
		throw AForm::GradeTooHighException("Too high - " + _name + "\n");
	}
	if (150 < _signGrade || 150 < _executeGrade){
		throw AForm::GradeTooLowException("Too low - " + _name + "\n");
	}
}

AForm::AForm(const AForm& _copy): name(_copy.name), approval(false), signGrade(_copy.signGrade), executeGrade(_copy.executeGrade){}

AForm&	AForm::operator=(const AForm& _aform){
	std::cout << _aform << "어케 호출함?\n";
	return *this;
}

AForm::~AForm(void){}

AForm::GradeTooHighException::GradeTooHighException(const std::string& _msg): std::logic_error(_msg){}

AForm::GradeTooLowException::GradeTooLowException(const std::string& _msg): std::logic_error(_msg){}

AForm::approvalException::approvalException(const std::string& _msg): std::logic_error(_msg){}

const std::string& AForm::getName(){
	return name;
}

const bool& AForm::getApproval(){
	return approval;
}

const int& AForm::getSignGrade(){
	return signGrade;
}

const int& AForm::getExecuteGrade(){
	return executeGrade;
}

const std::string& AForm::getName() const{
	return name;
}

const bool& AForm::getApproval() const{
	return approval;
}

const int& AForm::getSignGrade() const{
	return signGrade;
}

const int& AForm::getExecuteGrade() const{
	return executeGrade;
}

void	AForm::beSigned(const Bureaucrat& _bureaucrat){
	if (this->signGrade < _bureaucrat.getGrade()){
		throw AForm::GradeTooLowException(_bureaucrat.getName() + "'s grade is lower than " + this->name + "'s signGrade\n");
	}
	this->approval = true;
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (this->getExecuteGrade() < executor.getGrade()){
		throw AForm::GradeTooLowException("Too low - " + executor.getName() + "\n");
	}
	else if (this->getApproval() == false){
		throw AForm::approvalException("This form has not signed\n");
	}
	action();
}

std::ostream&	operator<<(std::ostream& _out, const AForm& _aform){
	_out << _aform.getName() << ", Form approval " << std::boolalpha << _aform.getApproval() << ", Form signGrade " << _aform.getSignGrade() << ", Form executeGrade " << _aform.getExecuteGrade() << '\n';
	return _out;
}
