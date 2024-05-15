#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
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

	class approvalException: public std::logic_error{
	public:
		approvalException(const std::string& _msg);
	private:
		approvalException(void);
	};

public:
	AForm(const std::string &_name, const int _signGrade, const int executeGrade);
	AForm(const AForm& _copy);
	virtual ~AForm(void);

	const std::string& getName();
	const bool& getApproval();
	const int& getSignGrade();
	const int& getExecuteGrade();
	const std::string& getName() const;
	const bool& getApproval() const;
	const int& getSignGrade() const;
	const int& getExecuteGrade() const;
	void	beSigned(const Bureaucrat& _bureaucrat);
	void	execute(Bureaucrat const & executor) const;
	virtual void	action(void) const = 0;

private:
	const std::string	name;
	bool				approval;
	const int			signGrade;
	const int			executeGrade;

	AForm(void);
	AForm&	operator=(const AForm& _aform);
};

std::ostream&	operator<<(std::ostream& _out, const AForm& _aform);

#endif
