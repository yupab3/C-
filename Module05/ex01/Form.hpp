#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
public:
	class GradeTooHighException: public std::logic_error{
	public:
		GradeTooHighException(const std::string& _msg);
	private:
		GradeTooHighException(void);
	};

	class GradeTooLowException: public std::logic_error{
	public:
		GradeTooLowException(const std::string& _msg);
	private:
		GradeTooLowException(void);
	};

public:
	Form(const std::string &_name, const int _signGrade, const int executeGrade);
	Form(const Form& _form);
	~Form(void);

	const std::string& getName();
	const bool& getApproval();
	const int& getSignGrade();
	const int& getExecuteGrade();
	const std::string& getName() const;
	const bool& getApproval() const;
	const int& getSignGrade() const;
	const int& getExecuteGrade() const;
	void	beSigned(const Bureaucrat& _bureaucrat);
private:
	const std::string	name;
	bool				approval;
	const int			signGrade;
	const int			executeGrade;

	Form(void);
	Form&	operator=(const Form& _form);
};

std::ostream&	operator<<(std::ostream& _out, const Form& _form);

#endif
