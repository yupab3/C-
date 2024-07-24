#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN& rhs);
	RPN&	operator=(const RPN& rhs);
	~RPN();

	void	solver(const std::string &input);

private:
	std::stack<ssize_t>	stk;
	size_t				pos;

	void	insertNum(const std::string &input);
	bool	isOperator(const std::string &input);
	void	jumpSpace(const std::string &input);
	void	calculator(const char op);
};

#endif