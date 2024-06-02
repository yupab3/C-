#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T, typename Ct = std::deque<T> >
class	MutantStack : public std::stack<T, Ct>
{
public:
	MutantStack():std::stack<T, Ct>(){};
	MutantStack(const MutantStack& copy):std::stack<T, Ct>(copy){};
	MutantStack& operator=(const MutantStack& copy)
	{
		this->std::stack<T, Ct>::operator=(copy);
	};
	~MutantStack(){};

	typedef	typename Ct::iterator		iterator;
	typedef	typename Ct::const_iterator	const_iterator;
	typedef	typename Ct::reverse_iterator		reverse_iterator;
	typedef	typename Ct::const_reverse_iterator	const_reverse_iterator;

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
	reverse_iterator	rbegin()
	{
		return this->c.rbegin();
	}
	reverse_iterator	rend()
	{
		return this->c.rend();
	}
	const_reverse_iterator	rbegin() const
	{
		return this->c.rbegin();
	}
	const_reverse_iterator	rend() const
	{
		return this->c.rend();
	}
};

#endif
