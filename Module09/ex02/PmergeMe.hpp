#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <list>
# include <vector>

# define ii	std::pair<int, int>

class	PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe& operator=(const PmergeMe &rhs);
	~PmergeMe();

	void	readNum(const std::string &str);

	void	vectorFordJohnson();

private:
	std::vector<ii>	_v_data;
	std::list<ii>	_l_data;
	int				_depth;

	bool	checkNum(const std::string &str, int pos);
	void	jumpSpace(const std::string &str, int &pos);
	void	splitData(std::vector<ii> &sub_chain, std::vector<ii>::iterator &it, int &idx);
};

#endif