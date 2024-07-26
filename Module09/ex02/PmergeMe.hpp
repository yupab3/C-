#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <deque>
# include <vector>
# include <sys/time.h>

# define ii	std::pair<int, int>

class	PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe& operator=(const PmergeMe &rhs);
	~PmergeMe();

	void	readNum(const std::string &str);
	// void	printData();
	void	printVectorData();
	void	printDequeData();
	void	vectorFordJohnson();
	void	dequeFordJohnson();
	int		getChain();
	int		getSize();

private:
	std::vector<ii>	_v_data;
	std::deque<ii>	_d_data;
	int				chain;

	void	setVectorIndex();
	void	setDequeIndex();
	void	callVectorIndex(std::vector<ii> &index);
	void	callDequeIndex(std::deque<ii> &index);
	void	jumpSpace(const std::string &str, int &pos);
	std::vector<ii>	setVectorSubchain(std::vector<ii> &sub_chain);
	std::deque<ii>	setDequeSubchain(std::deque<ii> &sub_chain);
	void	splitVectorData(std::vector<ii> &sub_chain, std::vector<ii>::iterator &it);
	void	splitDequeData(std::deque<ii> &sub_chain, std::deque<ii>::iterator &it);
};

#endif