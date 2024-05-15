#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
	// std::cout << "Bureaucrat 생성자 호출\n";
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade): name(_name), grade(_grade){
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException("Too high - " + _name + "\n");
	}
	if (150 < grade){
		throw Bureaucrat::GradeTooLowException("Too low - " + _name + "\n");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& _bureaucrat): name(_bureaucrat.name), grade(_bureaucrat.grade){}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& _bureaucrat){
	std::cout << _bureaucrat << "어케 호출함?\n";
	return *this;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& _msg): std::logic_error(_msg){}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& _msg): std::logic_error(_msg){}

const std::string& Bureaucrat::getName(){
	return name;
}

const int& Bureaucrat::getGrade(){
	return grade;
}

const std::string& Bureaucrat::getName() const{
	return name;
}

const int& Bureaucrat::getGrade() const{
	return grade;
}

void	Bureaucrat::signForm(AForm& _aform){
	try{
		_aform.beSigned(*this);
		std::cout << name << " signed " << _aform.getName() << '\n';
	}
	catch(std::exception &e){
		std::cout << name << " couldn’t sign " << _aform.getName() << " because " << e.what();
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << '\n';
	}
	catch(std::exception &e){
		std::cout << name << " couldn’t execute " << form.getName() << " because " << e.what();
	}
}

void	Bureaucrat::upGrade(void){
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException("wrong data (grade < 1)\n");
	}
	else if (grade > 150){
		throw Bureaucrat::GradeTooLowException("wrong data (grade > 150)\n");
	}
	else if (grade < 2){
		throw Bureaucrat::GradeTooHighException("Too high - upGrade\n");
	}
	--grade;
}

void	Bureaucrat::downGrade(void){
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException("wrong data (grade < 1)\n");
	}
	else if (grade > 150){
		throw Bureaucrat::GradeTooLowException("wrong data (grade > 150)\n");
	}
	else if (grade > 149){
		throw Bureaucrat::GradeTooLowException("Too low - downGrade\n");
	}
	++grade;
}

std::ostream&	operator<<(std::ostream& _out, const Bureaucrat& _bureaucrat){
	_out << _bureaucrat.getName() << ", bureaucrat grade " << _bureaucrat.getGrade() << '\n';
	return _out;
}
