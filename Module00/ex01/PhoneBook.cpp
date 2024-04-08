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

int	PhoneBook::chk_book_empty(void)
{
	int	idx;

	idx = 7;
	while (idx >= 0 && book[idx].is_empty())
	{
		idx--;
	}
	if (idx == (-1))
	{
		std::cout << "-- Book is empty --\n\n";
		return (1);
	}
	return (0);
}

int	PhoneBook::chk_index_wrong(std::string str)
{
	if (std::cin.eof() == 1)
	{
		std::cout << '\n';
		clearerr(stdin);
		std::cin.clear();
		std::cout << "--   data is empty --\n";
		std::cout << "-- please type again --\n";
		return (1);
	}
	if (str.size() > 1 || str[0] < '0' || '7' < str[0] || str[1] != '\0')
	{
		std::cout << " -- Wrong index, try again -- \n";
		return (1);
	}
	return (0);
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
	int			start;
	std::string	index;

	if (chk_book_empty())
	{
		return ;
	}
	idx--;
	if (idx == -1)
	{
		idx = 7;
	}
	start = idx;
	std::cout << std::setw(10) << "index" << '|' \
		<< std::setw(10) << "first name" << '|' \
		<< std::setw(10) << "last name" << '|' \
		<< std::setw(10) << "nickname" << '\n'
		<< "-------------------------------------------\n";
	while (book[idx].is_empty() == 0)
	{
		std::cout << std::setw(10) << idx << '|' \
		<< std::setw(10) << book[idx].get_first() << '|' \
		<< std::setw(10) << book[idx].get_last() << '|' \
		<< std::setw(10) << book[idx].get_nick() << '\n';
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
	while (1)
	{
		std::cout << "\nSelect_index: ";
		std::getline(std::cin, index);
		if (chk_index_wrong(index))
		{
			continue ;
		}
		if (index.empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		if (book[index[0] - 48].is_empty())
		{
			std::cout << "--   data is empty --\n";
			std::cout << "-- please type again --\n";
			continue ;
		}
		std::cout << "\nfirst name: " << book[index[0] - 48].get_org_first() << '\n';
		std::cout << "last name: " << book[index[0] - 48].get_org_last() << '\n';
		std::cout << "nickname: " << book[index[0] - 48].get_org_nick() << '\n';
		std::cout << "phone number: " << book[index[0] - 48].get_org_phone() << '\n';
		std::cout << "darkest secret: " << book[index[0] - 48].get_org_secret() << '\n';
		return ;
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