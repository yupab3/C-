#include "Span.hpp"

Span::Span(unsigned int N):maxSize(N), shortSpan(UINT_MAX){}

Span::Span(const Span& copy){
	*this = copy;
}

Span&	Span::operator=(const Span& copy){
	shortSpan = copy.shortSpan;
	maxSize = copy.maxSize;
	setInt = copy.setInt;
	return *this;
}

Span::~Span(){}

void	Span::addNumber(int input){
	if (setInt.size() >= maxSize)
		throw	std::out_of_range("\n  --Span overflow--\n");
	std::set<int>::iterator	tmpIt = setInt.insert(input).first;
	int tmpInteger;
	unsigned int compRes;
	if (tmpIt != --(setInt.end()))
	{
		tmpInteger = *(++tmpIt);
		compRes = tmpInteger - input;
		if (compRes < shortSpan)
			shortSpan = compRes;
		--tmpIt;
	}
	if (tmpIt != setInt.begin())
	{
		tmpInteger = *(--tmpIt);
		compRes = input - tmpInteger;
		if (compRes < shortSpan)
			shortSpan = compRes;
	}
}

unsigned int	Span::shortestSpan(){
	if (setInt.size() < 2)
		throw	std::out_of_range("\n  --Not enough data--\n");
	return shortSpan;
}

unsigned int	Span::longestSpan(){
	if (setInt.size() < 2)
		throw	std::out_of_range("\n  --Not enough data--\n");
	return *(--(setInt.end())) - *(setInt.begin());
}
