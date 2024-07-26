#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): chain(0) {}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	this->_v_data = rhs._v_data;
	this->_d_data = rhs._d_data;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_v_data = rhs._v_data;
		this->_d_data = rhs._d_data;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::vectorFordJohnson()
{
	if (_v_data.size() == 1)
		return ;
	std::vector<ii> index;
	setVectorIndex();
	std::vector<ii>	sub_chain;
	for (std::vector<ii>::iterator it = _v_data.begin(); it != _v_data.end();)
		splitVectorData(sub_chain, it);
	index = _v_data;
	if (_v_data.size() > 1)
		vectorFordJohnson();
	callVectorIndex(index);
	sub_chain = setVectorSubchain(sub_chain);
	_v_data.insert(_v_data.begin(), sub_chain[0]);
	size_t	bf = 1;
	int 	cycle = 3;
	while (sub_chain.size() > bf)
	{
		size_t	jacob = (pow(2, cycle) - pow(-1, cycle)) / 3;
		size_t	sub_idx = jacob - 1;
		if (sub_idx > sub_chain.size() - 1)
			sub_idx = sub_chain.size() - 1;
		size_t	start_sub_idx = sub_idx;
		while (sub_idx >= bf)
		{
			size_t	max_idx = (pow(2, cycle - 1) - (jacob - start_sub_idx));
			size_t	min_idx = 0;
			size_t	comp_idx = comp_idx = (max_idx + min_idx) / 2;;
			while (max_idx != min_idx)
			{
				if (_v_data[comp_idx].first == sub_chain[sub_idx].first)
					break ;
				else if (_v_data[comp_idx].first > sub_chain[sub_idx].first)
					max_idx = comp_idx;
				else if (_v_data[comp_idx].first < sub_chain[sub_idx].first)
					min_idx = comp_idx + 1;
				comp_idx = (max_idx + min_idx) / 2;
				chain++;
			}
			std::vector<ii>::iterator it = _v_data.begin() + comp_idx;
			_v_data.insert(it, sub_chain[sub_idx]);
			sub_idx--;
		}
		bf = jacob;
		cycle++;
	}
}

void	PmergeMe::dequeFordJohnson()
{
	if (_d_data.size() == 1)
		return ;
	std::deque<ii> index;
	setDequeIndex();
	std::deque<ii>	sub_chain;
	for (std::deque<ii>::iterator it = _d_data.begin(); it != _d_data.end();)
		splitDequeData(sub_chain, it);
	index = _d_data;
	if (_d_data.size() > 1)
		dequeFordJohnson();
	callDequeIndex(index);
	sub_chain = setDequeSubchain(sub_chain);
	_d_data.insert(_d_data.begin(), sub_chain[0]);
	size_t	bf = 1;
	int 	cycle = 3;
	while (sub_chain.size() > bf)
	{
		size_t	jacob = (pow(2, cycle) - pow(-1, cycle)) / 3;
		size_t	sub_idx = jacob - 1;
		if (sub_idx > sub_chain.size() - 1)
			sub_idx = sub_chain.size() - 1;
		size_t	start_sub_idx = sub_idx;
		while (sub_idx >= bf)
		{
			size_t	max_idx = (pow(2, cycle - 1) - (jacob - start_sub_idx));
			size_t	min_idx = 0;
			size_t	comp_idx = comp_idx = (max_idx + min_idx) / 2;;
			while (max_idx != min_idx)
			{
				if (_d_data[comp_idx].first == sub_chain[sub_idx].first)
					break ;
				else if (_d_data[comp_idx].first > sub_chain[sub_idx].first)
					max_idx = comp_idx;
				else if (_d_data[comp_idx].first < sub_chain[sub_idx].first)
					min_idx = comp_idx + 1;
				comp_idx = (max_idx + min_idx) / 2;
			}
			std::deque<ii>::iterator it = _d_data.begin() + comp_idx;
			_d_data.insert(it, sub_chain[sub_idx]);
			sub_idx--;
		}
		bf = jacob;
		cycle++;
	}
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
		_v_data.push_back(data);
		_d_data.push_back(data);
	}
}

void	PmergeMe::jumpSpace(const std::string &str, int &pos)
{
	while (str[pos] == ' ' || str[pos] == '\t')
		++pos;
}

void	PmergeMe::splitVectorData(std::vector<ii> &sub_chain, std::vector<ii>::iterator &it)
{
	std::vector<ii>::iterator	next = ++it;
	--it;
	if (next == _v_data.end())
	{
		sub_chain.push_back(*it);
		it = _v_data.erase(it);
	}
	else if (next->first >= it->first)
	{
		sub_chain.push_back(*it);
		it = _v_data.erase(it);
		++it;
	}
	else if (next->first < it->first)
	{
		sub_chain.push_back(*next);
		it = _v_data.erase(next);
	}
}

void	PmergeMe::splitDequeData(std::deque<ii> &sub_chain, std::deque<ii>::iterator &it)
{
	std::deque<ii>::iterator	next = ++it;
	--it;
	if (next == _d_data.end())
	{
		sub_chain.push_back(*it);
		it = _d_data.erase(it);
	}
	else if (next->first >= it->first)
	{
		sub_chain.push_back(*it);
		it = _d_data.erase(it);
		++it;
	}
	else if (next->first < it->first)
	{
		sub_chain.push_back(*next);
		it = _d_data.erase(next);
	}
}

std::vector<ii>	PmergeMe::setVectorSubchain(std::vector<ii> &sub_chain)
{
	std::vector<ii>	new_sub_chain;
	std::vector<ii>::iterator	main_it = _v_data.begin();
	while (main_it != _v_data.end())
	{
		for (std::vector<ii>::iterator	sub_it = sub_chain.begin(); sub_it != sub_chain.end(); ++sub_it)
		{
			if (main_it->second / 2 == sub_it->second / 2)
			{
				new_sub_chain.push_back(*sub_it);
				sub_chain.erase(sub_it);
				break ;
			}
		}
		++main_it;
	}
	std::vector<ii>::iterator	tmp_it = sub_chain.begin();
	if (tmp_it != sub_chain.end())
	{
		new_sub_chain.push_back(*tmp_it);
		sub_chain.erase(tmp_it);
	}
	return (new_sub_chain);
}

std::deque<ii>	PmergeMe::setDequeSubchain(std::deque<ii> &sub_chain)
{
	std::deque<ii>	new_sub_chain;
	std::deque<ii>::iterator	main_it = _d_data.begin();
	while (main_it != _d_data.end())
	{
		for (std::deque<ii>::iterator	sub_it = sub_chain.begin(); sub_it != sub_chain.end(); ++sub_it)
		{
			if (main_it->second / 2 == sub_it->second / 2)
			{
				new_sub_chain.push_back(*sub_it);
				sub_chain.erase(sub_it);
				break ;
			}
		}
		++main_it;
	}
	std::deque<ii>::iterator	tmp_it = sub_chain.begin();
	if (tmp_it != sub_chain.end())
	{
		new_sub_chain.push_back(*tmp_it);
		sub_chain.erase(tmp_it);
	}
	return (new_sub_chain);
}

void	PmergeMe::printVectorData()
{
	for (std::vector<ii>::iterator it = _v_data.begin(); it != _v_data.end();)
	{
		std::cout << it->first;
		if (++it != _v_data.end())
			std::cout << " ";
	}
	std::cout << '\n';
}

void	PmergeMe::printDequeData()
{
	for (std::deque<ii>::iterator it = _d_data.begin(); it != _d_data.end();)
	{
		std::cout << it->first;
		if (++it != _d_data.end())
			std::cout << " ";
	}
	std::cout << '\n';
}

void	PmergeMe::setVectorIndex()
{
	int	idx = 0;
	for (std::vector<ii>::iterator it = _v_data.begin(); it != _v_data.end();)
	{
		it->second = idx++;
		++it;
	}
}

void	PmergeMe::setDequeIndex()
{
	int	idx = 0;
	for (std::deque<ii>::iterator it = _d_data.begin(); it != _d_data.end();)
	{
		it->second = idx++;
		++it;
	}
}

void	PmergeMe::callVectorIndex(std::vector<ii> &index)
{
	std::vector<ii>::iterator	main_it = _v_data.begin();
	while (main_it != _v_data.end())
	{
		for (std::vector<ii>::iterator	idx_it = index.begin(); idx_it != index.end(); ++idx_it)
		{
			if (main_it->first == idx_it->first)
			{
				main_it->second = idx_it->second;
				index.erase(idx_it);
				break ;
			}
		}
		++main_it;
	}
}

void	PmergeMe::callDequeIndex(std::deque<ii> &index)
{
	std::deque<ii>::iterator	main_it = _d_data.begin();
	while (main_it != _d_data.end())
	{
		for (std::deque<ii>::iterator	idx_it = index.begin(); idx_it != index.end(); ++idx_it)
		{
			if (main_it->first == idx_it->first)
			{
				main_it->second = idx_it->second;
				index.erase(idx_it);
				break ;
			}
		}
		++main_it;
	}
}

int		PmergeMe::getChain()
{
	return chain;
}

int		PmergeMe::getSize()
{
	return _v_data.size();
}
