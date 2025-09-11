#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <class C>
void	try_find(C& c, int x, const char* name)
{
	std::cout << "Searching for " << x << " in " << name << ": ";
	try {
		typename C::const_iterator it = easyfind(static_cast<const C&>(c), x);
		std::cout << "found value " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "not found (" << e.what() << ")" << std::endl;
	}
}

int	main(void)
{
	std::vector<int> v;
	for (int i = 0; i < 5; ++i) v.push_back(i * 10);
	try_find(v, 20, "vector");
	try_find(v, 99, "vector");

	std::list<int> L;
	L.push_back(-3);
	L.push_back(-1);
	L.push_back(2);
	L.push_back(4);
	try_find(L, -1, "list");
	try_find(L, 5, "list");

	std::deque<int> d;
	d.push_back(7);
	d.push_back(8);
	d.push_back(9);
	try {
		std::deque<int>::iterator it = easyfind(d, 7);
		std::cout << "deque: first 7 = " << *it << std::endl;
		++it;
		std::cout << "deque: next element = " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "deque: " << e.what() << std::endl;
	}

	const std::vector<int> cv(v);
	try {
		std::vector<int>::const_iterator it = easyfind(cv, 30);
		std::cout << "const vector: found " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "const vector: " << e.what() << std::endl;
	}

	return (0);
}