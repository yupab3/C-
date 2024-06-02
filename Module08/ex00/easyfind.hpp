#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T& container, int idx)
{
	return std::find(container.begin(), container.end(), idx);
}

template<typename T>
typename T::const_iterator	easyfind(const T& container, int idx)
{
	return std::find(container.begin(), container.end(), idx);
}

#endif
