#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:

	Contact(void);
	~Contact(void);

	int	set_first(void);
	int	set_last(void);
	int	set_nick(void);
	int	set_phone(void);
	int	set_secret(void);

	std::string	get_first(void);
	std::string	get_last(void);
	std::string	get_nick(void);
	std::string	get_phone(void);
	std::string	get_secret(void);

	int	is_empty(void);

};

#endif