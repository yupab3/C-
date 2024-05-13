#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat{
public:
	class GradeTooHighException: public std::logic_error{
	public:
		GradeTooHighException(const std::string& _msg);
	private:
		GradeTooHighException(void);
	};
	// class GradeTooHighException{
	// public:
	// 	GradeTooHighException(void);
	// 	GradeTooHighException(const std::string& _msg);
	// 	const char*	what(void);
	// private:
	// 	const std::string	msg;
	// };
	class GradeTooLowException: public std::logic_error{
	public:
		GradeTooLowException(const std::string& _msg);
	private:
		GradeTooLowException(void);
	};
	// class GradeTooLowException{
	// public:
	// 	GradeTooLowException(void);
	// 	GradeTooLowException(const std::string& _msg);
	// 	const char*	what(void);
	// private:
	// 	const std::string	msg;
	// };

public:
	Bureaucrat(const std::string &_name, int _grade);
	Bureaucrat(const Bureaucrat& _bureaucrat);
	~Bureaucrat(void);

	const std::string& getName();
	const int& getGrade();
	const std::string& getName() const;
	const int& getGrade() const;
private:
	const std::string	name;
	int	grade;

	Bureaucrat(void);
	Bureaucrat&	operator=(const Bureaucrat& _bureaucrat);
};

std::ostream&	operator<<(std::ostream& _out, const Bureaucrat& _bureaucrat);

#endif
