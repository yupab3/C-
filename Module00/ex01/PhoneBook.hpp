#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook{

private:
	int		idx;
	Contact	book[8];

public:

	PhoneBook(void);
	~PhoneBook(void);

	int		ADD(void);
	void	SEARCH(void);

};

#endif