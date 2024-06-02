#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <stdexcept>
#include <climits>
#include <iostream>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& copy);
	Span&	operator=(const Span& copy);
	~Span();
	void	addNumber(int input);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	template<typename T>
	void	fill(T beginIt, T endIt)
	{
		for	(T tmpIt = beginIt; tmpIt != endIt; tmpIt++)
			addNumber(*tmpIt);
	}

private:
	Span();
	std::set<int>	setInt;
	unsigned int	maxSize;
	unsigned int	shortSpan;
};

#endif
