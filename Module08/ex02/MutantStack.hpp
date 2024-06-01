#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T, typename Ct = std::deque<T> >
class	MutantStack : public std::stack<T, Ct>
{
public:
	MutantStack():std::stack<T, Ct>(){};
	MutantStack(const MutantStack& copy):std::stack<T, Ct>(static_cast<const std::stack<T, Ct> >(copy)){};
	MutantStack& operator=(const MutantStack& copy)
	{
		this->std::stack<T, Ct>::operator=(static_cast<const std::stack<T, Ct> >(copy));
	};
	~MutantStack(){};

	typedef	typename Ct::iterator		iterator;
	typedef	typename Ct::const_iterator	const_iterator;

	iterator	begin()
	{
		return this->c.begin();
	}
	iterator	end()
	{
		return this->c.end();
	}
	const_iterator	begin() const
	{
		return this->c.begin();
	}
	const_iterator	end() const
	{
		return this->c.end();
	}
};

#endif
