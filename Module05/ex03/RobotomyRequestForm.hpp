#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm: public AForm{
public:
	class FileError: public std::logic_error{
	public:
		FileError(const std::string& _msg);
	private:
		FileError(void);
	};

public:
	RobotomyRequestForm(const std::string &_target);
	RobotomyRequestForm(const RobotomyRequestForm& _copy);
	virtual ~RobotomyRequestForm(void);
	void	action(void) const;
	const std::string&	getTarget(void) const;

private:
	std::string	target;

	RobotomyRequestForm(void);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& _form);
};

std::ostream&	operator<<(std::ostream& _out, const RobotomyRequestForm& _form);

#endif
