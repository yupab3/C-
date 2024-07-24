#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _depth(0) {}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	this->_v_data = rhs._v_data;
	this->_l_data = rhs._l_data;
	this->_depth = rhs._depth;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_v_data = rhs._v_data;
		this->_l_data = rhs._l_data;
		this->_depth = rhs._depth;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::vectorFordJohnson()
{
	std::vector<ii>	sub_chain;
	int	idx = 0;
	for (std::vector<ii>::iterator it = _v_data.begin(); it != _v_data.end();)
		splitData(sub_chain, it, idx);
	if (_v_data.size() > 1)
		vectorFordJohnson();
	
	// std::cout << '\n';
	// for (std::vector<ii>::iterator it = _v_data.begin(); it != _v_data.end();)
	// {
	// 	std::cout << it->first << "-" << it->second << " ";
	// 	++it;
	// }
	// std::cout << '\n';
	// for (std::vector<ii>::iterator it = sub_chain.begin(); it != sub_chain.end();)
	// {
	// 	std::cout << it->first << "-" << it->second << " ";
	// 	++it;
	// }
}

void	PmergeMe::readNum(const std::string &str)
{
	std::stringstream	ss;
	ss << str;
	while (!ss.eof())
	{
		int	num;
		ss >> num;
		if (ss.fail())
			throw std::logic_error("Error - wrong char [readNum]\n");
		ii	data = std::make_pair(num, 0);
		std::cout << data.first << " " << data.second << '\n';
		_v_data.push_back(data);
		_l_data.push_back(data);
	}
}

void	PmergeMe::jumpSpace(const std::string &str, int &pos)
{
	while (str[pos] == ' ' || str[pos] == '\t')
		++pos;
}

void	PmergeMe::splitData(std::vector<ii> &sub_chain, std::vector<ii>::iterator &it, int &idx)
{
	std::vector<ii>::iterator	next = ++it;
	--it;
	if (next == _v_data.end())
	{
		sub_chain.push_back(std::make_pair(it->first, idx));
		it = _v_data.erase(it);
	}
	else if (next->first > it->first)
	{
		next->second = idx;
		idx++;
		sub_chain.push_back(std::make_pair(it->first, idx));
		idx++;
		it = _v_data.erase(it);
		++it;
	}
	else if (next->first < it->first)
	{
		it->second = idx;
		idx++;
		sub_chain.push_back(std::make_pair(next->first, idx));
		idx++;
		it = _v_data.erase(next);
	}
}