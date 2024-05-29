#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T& val1, T& val2)
{
	T	tmp;
	tmp = val1;
	val1 = val2;
	val2 = tmp;
}

template<typename T>
T	min(T val1, T val2)
{
	return val1 < val2 ? val1 : val2;
}

// template<>
// int	min<int>(int val1, int val2)
// // int	min(int val1, int val2)
// {
// 	std::cout << "call const template func1\n";
// 	return val1 < val2 ? val1 : val2;
// }

// template<>
// const int	min<const int>(const int val1, const int val2)
// int	min(const int val1, const int val2)
// {
// 	std::cout << "call const template func3\n";
// 	return val1 < val2 ? val1 : val2;
// }

template<typename T>
T	max(T val1, T val2)
{
	return val1 > val2 ? val1 : val2;
}

#endif
