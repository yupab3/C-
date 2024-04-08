#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook{

private:
	int		idx;
	Contact	book[8];

	int	chk_index_wrong(std::string str) const;
	int	chk_book_empty(void) const;
	
public:

	PhoneBook(void);
	~PhoneBook(void);

	int		ADD(void);
	void	SEARCH(void);

};

#endif