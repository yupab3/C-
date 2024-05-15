#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
public:
	class FileError: public std::logic_error{
	public:
		FileError(const std::string& _msg);
	private:
		FileError(void);
	};

public:
	ShrubberyCreationForm(const std::string &_target);
	ShrubberyCreationForm(const ShrubberyCreationForm& _copy);
	virtual ~ShrubberyCreationForm(void);
	void	action(void) const;
	const std::string&	getTarget(void) const;

private:
	std::string target;

	ShrubberyCreationForm(void);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& _form);
};

std::ostream&	operator<<(std::ostream& _out, const ShrubberyCreationForm& _form);

#endif
