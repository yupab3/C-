#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "Constructor called\n";
	return ;
}

Contact::~Contact(void){
	std::cout << "Destructor called\n";
	return ;
}

void	Contact::ignore_ctrl_d(void) const
{
	std::cout << '\n';
	clearerr(stdin);
	std::cin.clear();
	std::cout << "--   data is empty --\n";
	std::cout << "-- please type again --\n";
}

int	Contact::chk_str_wrong(std::string str) const
{
	size_t	i;

	for (i = 0; i < str.size(); i++)
	{
		if (std::isprint(str[i]) == 0)
		{
			std::cout << " -- Wrong string, try again -- \n";
			break ;
		}
	}
	if (i != str.size())
	{
		return (1);
	}
	return (0);
}

static int	chk_number_wrong(std::string str)
{
	size_t	i;

	for (i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == 0)
		{
			std::cout << " -- Wrong number, try again -- \n";
			break ;
		}
	}
	if (i != str.size())
	{
		return (1);
	}
	return (0);
}

int	Contact::set_first(void)
{
	std::string	str;

	while (1)
	{
		std::cout << "first_name: ";
		std::getline(std::cin, str);
		if (chk_str_wrong(str))
		{
			continue ;
		}
		if (std::cin.eof() == 1)
		{
			ignore_ctrl_d();
			continue ;
		}
		if (str.empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		first_name = str;
		return (1);
	}
}

int	Contact::set_last(void)
{
	std::string	str;

	while (1)
	{
		std::cout << "last_name: ";
		std::getline(std::cin, str);
		if (chk_str_wrong(str))
		{
			continue ;
		}
		if (std::cin.eof() == 1)
		{
			ignore_ctrl_d();
			continue ;
		}
		if (str.empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		last_name = str;
		return (1);
	}
}

int	Contact::set_nick(void)
{
	std::string	str;

	while (1)
	{
		std::cout << "nick_name: ";
		std::getline(std::cin, str);
		if (chk_str_wrong(str))
		{
			continue ;
		}
		if (std::cin.eof() == 1)
		{
			ignore_ctrl_d();
			continue ;
		}
		if (str.empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		nickname = str;
		return (1);
	}
}

int	Contact::set_phone(void)
{
	std::string	str;

	while (1)
	{
		std::cout << "phone_number: ";
		std::getline(std::cin, str);
		if (chk_number_wrong(str))
		{
			continue ;
		}
		if (std::cin.eof() == 1)
		{
			ignore_ctrl_d();
			continue ;
		}
		if (str.empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		phone_number = str;
		return (1);
	}
}

int	Contact::set_secret(void)
{
	std::string	str;

	while (1)
	{
		std::cout << "darkest_secret: ";
		std::getline(std::cin, str);
		if (chk_str_wrong(str))
		{
			continue ;
		}
		if (std::cin.eof() == 1)
		{
			ignore_ctrl_d();
			continue ;
		}
		if (str.empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		darkest_secret = str;
		return (1);
	}
}

const std::string	Contact::get_first(void) const
{
	std::string	str;

	str = first_name;
	if (str.size() > 10)
	{
		str.resize(10);
		str.replace(9,1, ".");
	}
	return (str);
}

const std::string	Contact::get_last(void) const
{
	std::string	str;

	str = last_name;
	if (str.size() > 10)
	{
		str.resize(10);
		str.replace(9,1, ".");
	}
	return (str);
}

const std::string	Contact::get_nick(void) const
{
	std::string	str;

	str = nickname;
	if (str.size() > 10)
	{
		str.resize(10);
		str.replace(9,1, ".");
	}
	return (str);
}

const std::string&	Contact::get_org_first(void) const
{
	return (first_name);
}

const std::string&	Contact::get_org_last(void) const
{
	return (last_name);
}

const std::string&	Contact::get_org_nick(void) const
{
	return (nickname);
}

const std::string&	Contact::get_org_phone(void) const
{
	return (phone_number);
}

const std::string&	Contact::get_org_secret(void) const
{
	return (darkest_secret);
}


int	Contact::is_empty(void) const
{
	return (darkest_secret.empty());
}