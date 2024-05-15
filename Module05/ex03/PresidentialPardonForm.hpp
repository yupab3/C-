#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm{
public:
	PresidentialPardonForm(const std::string &_target);
	PresidentialPardonForm(const PresidentialPardonForm& _copy);
	virtual ~PresidentialPardonForm(void);
	void	action(void) const;
	const std::string&	getTarget(void) const;

private:
	std::string	target;

	PresidentialPardonForm(void);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& _form);
};

std::ostream&	operator<<(std::ostream& _out, const PresidentialPardonForm& _form);

#endif
