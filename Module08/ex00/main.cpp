#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <set>
#include <stack>

// void	asd(void)
// {
// 	system("leaks main");
// }

int	main(void)
{
	std::vector<int>	vectorInt;
	std::vector<int>::iterator	vectorIntIt;
	int	idx;

	vectorInt.push_back(1);
	vectorInt.push_back(2);
	vectorInt.push_back(3);
	vectorInt.push_back(4);
	idx = 2;
	vectorIntIt = easyfind(vectorInt, idx);

	std::cout << "\n  --Vector case--\n";

	if (vectorIntIt != vectorInt.end()) { std::cout << idx << " : exist\n"; }
	else { std::cout << idx << " : does not exist\n"; }

	idx = 5;
	vectorIntIt = easyfind(vectorInt, idx);
	if (vectorIntIt != vectorInt.end()) { std::cout << idx << " : exist\n"; }
	else { std::cout << idx << " : does not exist\n"; }

	// ------------------

	std::set<int>	setInt;
	std::set<int>::iterator	setIntIt;

	setInt.insert(1);
	setInt.insert(2);
	setInt.insert(3);
	setInt.insert(4);
	idx = 2;
	setIntIt = easyfind(setInt, idx);

	std::cout << "\n  --Set case--\n";

	if (setIntIt != setInt.end()) { std::cout << idx << " : exist\n"; }
	else { std::cout << idx << " : does not exist\n"; }

	idx = 5;
	setIntIt = easyfind(setInt, idx);
	if (setIntIt != setInt.end()) { std::cout << idx << " : exist\n"; }
	else { std::cout << idx << " : does not exist\n"; }

	// ------------------

	std::stack<int>	stackInt;
	// std::stack<int>::iterator	stackIntIt; ?????

	stackInt.push(1);
	stackInt.push(2);
	stackInt.push(3);
	stackInt.push(4);
	idx = 2;

	std::cout << "\n  --Stack case--\n   no-iterator\n";

	// stackIntIt = easyfind(stackInt, idx);
	// if (stackIntIt != stackInt.end()) { std::cout << idx << " : exist\n"; }
	// else { std::cout << idx << " : does not exist\n"; }

	idx = 5;
	// stackIntIt = easyfind(stackInt, idx);
	// if (stackIntIt != stackInt.end()) { std::cout << idx << " : exist\n"; }
	// else { std::cout << idx << " : does not exist\n"; }
	// atexit(asd);
	return 0;
}