#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <stdexcept>
#include <climits>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& copy);
	Span&	operator=(const Span& copy);
	~Span();
	void	addNumber(int input);
	int		shortestSpan();
	int		longestSpan();

	template<typename T>
	void	fill(T beginIt, T endIt)
	{
		if (std::distance(setInt.begin(), setInt.end()) + std::distance(beginIt, endIt) > maxSize)
			throw	std::out_of_range("\n  --Span overflow--\n");
		for	(T tmpIt = beginIt; tmpIt != endIt; tmpIt++)
		{
			setInt.insert(*tmpIt);
		}
	}

private:
	Span();
	std::set<int>	setInt;
	unsigned int	maxSize;
};

#endif
