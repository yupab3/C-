#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
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
	Bureaucrat(const std::string &_name, int _grade);
	Bureaucrat(const Bureaucrat& _copy);
	~Bureaucrat(void);

	const std::string& getName();
	const int& getGrade();
	const std::string& getName() const;
	const int& getGrade() const;
	void	signForm(Form& _form);
	void	upGrade(void);
	void	downGrade(void);
private:
	const std::string	name;
	int	grade;

	Bureaucrat(void);
	Bureaucrat&	operator=(const Bureaucrat& _bureaucrat);
};

std::ostream&	operator<<(std::ostream& _out, const Bureaucrat& _bureaucrat);

#endif
