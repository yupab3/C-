#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("", 0, 0){
	// std::cout << "Form 생성자 호출\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target): AForm("ShrubberyCreationForm", 145, 137){
	target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _copy): AForm(_copy.getName(), _copy.getSignGrade(), _copy.getExecuteGrade()){
	target = _copy.target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& _form){
	std::cout << _form << "어케 호출함?\n";
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm::FileError::FileError(const std::string& _msg): std::logic_error(_msg){}

void	ShrubberyCreationForm::action(void) const{
	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile.is_open()){
		throw ShrubberyCreationForm::FileError("Ofstream open error - " + this->getName() + "\n");
	}
	outfile.write("    0     0  \nO   | O   | O\n| o | | o | |\n| | | | | | |\n", 56);
	outfile.close();
	if (outfile.is_open()){
		throw ShrubberyCreationForm::FileError("Ofstream close error - " + this->getName() + "\n");
	}
}

const std::string&	ShrubberyCreationForm::getTarget(void) const{
	return target;
}

std::ostream&	operator<<(std::ostream& _out, const ShrubberyCreationForm& _form){
	_out << _form.getName() << ", Form approval " << std::boolalpha << _form.getApproval() << ", Form signGrade " << _form.getSignGrade() << ", Form executeGrade " << _form.getExecuteGrade() << ", Target " << _form.getTarget() << '\n';
	return _out;
}
