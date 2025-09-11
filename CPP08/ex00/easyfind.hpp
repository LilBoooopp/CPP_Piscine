#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <class T>
typename T::iterator	easyfind(T& a, int n)
{
	typename T::iterator it = std::find(a.begin(), a.end(), n);
	if (it == a.end())
		throw std::out_of_range("easyfind: value not found");
	return (it);
}

template <class T>
typename T::const_iterator easyfind(const T& a, int n)
{
	typename T::const_iterator it = std::find(a.begin(), a.end(), n);
	if (it == a.end())
		throw std::out_of_range("easyfind: value not found");
	return (it);
}

#endif