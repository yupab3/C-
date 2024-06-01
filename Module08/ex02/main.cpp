#include <iostream>
#include "MutantStack.hpp"
#include <list>

// namespace aaa
// {
// class	A
// {
// public:
// 	A& operator=(const A& copy);
// };

// A& A::operator=(const A& copy)
// {
// 	return *this;
// }
// }

// class	B: public aaa::A
// {
// public:
// 	B& operator=(const B& copy);
// };

// B&	B::operator=(const B& copy)
// {
// 	this->aaa::A::operator=(static_cast<const A&>(copy));
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	MutantStack<int, std::list<int> > mliststack;
	mliststack.push(5);
	mliststack.push(17);
	std::cout << mliststack.top() << std::endl;
	mliststack.pop();
	std::cout << mliststack.size() << std::endl;
	mliststack.push(3);
	mliststack.push(5);
	mliststack.push(737);
	//[...]
	mliststack.push(0);
	MutantStack<int, std::list<int> >::iterator mlit = mliststack.begin();
	MutantStack<int, std::list<int> >::iterator mlite = mliststack.end();
	++mlit;
	--mlit;
	while (mlit != mlite)
	{
		std::cout << *mlit << std::endl;
		++mlit;
	}
	std::stack<int, std::list<int> > sl(mliststack);

	std::list<int> reallyst;
	reallyst.push_back(5);
	reallyst.push_back(17);
	std::cout << reallyst.back() << std::endl;
	reallyst.pop_back();
	std::cout << reallyst.size() << std::endl;
	reallyst.push_back(3);
	reallyst.push_back(5);
	reallyst.push_back(737);
	//[...]
	reallyst.push_back(0);
	std::list<int>::iterator rllstit = reallyst.begin();
	std::list<int>::iterator rllstite = reallyst.end();
	++rllstit;
	--rllstit;
	while (rllstit != rllstite)
	{
		std::cout << *rllstit << std::endl;
		++rllstit;
	}
	
	// std::stack<int> s(reallyst);
	system("leaks main");
	return 0;
}