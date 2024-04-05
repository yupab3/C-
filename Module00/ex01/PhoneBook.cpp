#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "Constructor called\n";
	idx = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Destructor called\n";
	return ;
}

int	PhoneBook::ADD(void){
	if (book[idx].set_first() && book[idx].set_last() && book[idx].set_nick() \
		&& book[idx].set_phone() && book[idx].set_secret())
	{
		idx++;
		if (idx == 8)
		{
			idx = 0;
		}
		return (1);
	}
	return (0);
}

void	PhoneBook::SEARCH(void){
	int	start;

	idx--;
	if (idx == -1)
	{
		idx = 7;
	}
	start = idx;
	std::cout << std::setw(10) << "first" << '|' \
		<< std::setw(10) << "last" << '|' \
		<< std::setw(10) << "nick" << '|' \
		<< std::setw(10) << "phone" << '\n'
		<< "-------------------------------------------\n";
	while (book[idx].is_empty() == 0)
	{
		std::cout << std::setw(10) << book[idx].get_first() << '|' \
		<< std::setw(10) << book[idx].get_last() << '|' \
		<< std::setw(10) << book[idx].get_nick() << '|' \
		<< std::setw(10) << book[idx].get_phone() << '\n';
		idx--;
		if (idx == start)
		{
			break ;
		}
		if (idx == -1)
		{
			idx = 7;
			if (idx == start)
			{
				break ;
			}
		}
	}
	idx = start + 1;
	if (idx == 8)
	{
		idx = 0;
	}
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	PB;
	size_t		i;

	while (1)
	{
		std::cout << " Options\n1. ADD\n2. SEARCH\n3. EXIT\n";
		std::getline(std::cin, cmd);
		for (i = 0; i < cmd.size(); i++)
		{
			if (std::isprint(cmd[i]) == 0)
			{
				std::cout << " -- Wrong command, try again -- \n";
				break ;
			}
		}
		if (i != cmd.size())
		{
			continue ;
		}
		if (std::cin.eof() == 1)
		{
			return (0);
		}
		if (cmd == "ADD")
		{
			PB.ADD();
		}
		else if (cmd == "SEARCH")
		{
			PB.SEARCH();
		}
		else if (cmd == "EXIT")
		{
			return (0);
		}
		else
		{
			std::cout << " -- Wrong command, try again -- \n";
		}
	}
}