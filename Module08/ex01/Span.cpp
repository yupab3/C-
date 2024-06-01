#include "Span.hpp"

Span::Span(unsigned int N){
	maxSize = N;
}

Span::Span(const Span& copy){
	*this = copy;
}

Span&	Span::operator=(const Span& copy){
	maxSize = copy.maxSize;
	setInt = copy.setInt;
	return *this;
}

Span::~Span(){}

void	Span::addNumber(int input){
	if (std::distance(setInt.begin(), setInt.end()) >= maxSize)
		throw	std::out_of_range("\n  --Span overflow--\n");
	setInt.insert(input);
}

int		Span::shortestSpan(){
	if (std::distance(setInt.begin(), setInt.end()) < 2)
		throw	std::out_of_range("\n  --Not enough data--\n");
	int	res = INT32_MAX;
	std::set<int>::iterator tmp = setInt.begin();
	int	bfValue = *tmp;
	tmp++;
	for (; tmp != setInt.end(); tmp++)
	{
		if (*tmp - bfValue < res)
			res = *tmp - bfValue;
		bfValue = *tmp;
	}
	return res;
}

int		Span::longestSpan(){
	if (std::distance(setInt.begin(), setInt.end()) < 2)
		throw	std::out_of_range("\n  --Not enough data--\n");
	return *(--(setInt.end())) - *(setInt.begin());
}
