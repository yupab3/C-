#include "RPN.hpp"

RPN::RPN(): pos(0) {}

RPN::RPN(const RPN& rhs): stk(rhs.stk), pos(rhs.pos) {}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		pos = rhs.pos;
		stk = rhs.stk;
	}
	return (*this);
}

RPN::~RPN() {}

void	RPN::solver(const std::string &input)
{
	while(input[pos] != '\0')
	{
		jumpSpace(input);
		if (input[pos] == '\0')
			break ;
		if (isOperator(input))
			calculator(input[pos]);
		else
			insertNum(input);
	}
	if (stk.size() != 1)
		throw std::logic_error("Error - mathematical expression is wrong [insertNum]\n");
	std::cout << stk.top() << '\n';
}

void	RPN::insertNum(const std::string &input)
{
	if (!std::isdigit(input[pos]))
		throw std::logic_error("Error - other char, expect num [insertNum]\n");
	if (std::isdigit(input[pos + 1]))
		throw std::logic_error("Error - too large num [insertNum]\n");
	stk.push(input[pos] - 48);
	++pos;
}

bool	RPN::isOperator(const std::string &input)
{
	if (input[pos] != '+' && input[pos] != '-' && input[pos] != '*' && input[pos] != '/')
	{
		if (isdigit(input[pos]))
			return (false);
		else
			throw std::logic_error("Error - other char, expect op [insertNum]\n");
	}
	return (true);
}

void	RPN::jumpSpace(const std::string &input)
{
	while (input[pos] == ' ' || input[pos] == '\t')
		++pos;
}

void	RPN::calculator(const char op)
{
	if (stk.size() < 2)
		throw std::logic_error("Error - need 2 numbers to calculate [calculator]\n");
	ssize_t	lhs, rhs; // front, back (front opertor back = ans)
	rhs = stk.top();
	stk.pop();
	lhs = stk.top();
	stk.pop();
	if (op == '+')
		stk.push(lhs + rhs);
	else if (op == '-')
		stk.push(lhs - rhs);
	else if (op == '*')
		stk.push(lhs * rhs);
	else if (rhs == 0)
		throw std::logic_error("Error - div by zero [calculator]\n");
	else
		stk.push(lhs / rhs);
	std::cout << stk.top() << '\n';
	pos++;
}
