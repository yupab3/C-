#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdio>

class Contact{

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	void	ignore_ctrl_d(void) const;
	int		chk_str_wrong(std::string str) const;

public:

	Contact(void);
	~Contact(void);

	int	set_first(void);
	int	set_last(void);
	int	set_nick(void);
	int	set_phone(void);
	int	set_secret(void);

	const std::string	get_first(void) const;
	const std::string	get_last(void) const;
	const std::string	get_nick(void) const;

	const std::string&	get_org_first(void) const;
	const std::string&	get_org_last(void) const;
	const std::string&	get_org_nick(void) const;
	const std::string&	get_org_phone(void) const;
	const std::string&	get_org_secret(void) const;

	int	is_empty(void) const;

};

#endif