#include <iostream>
#include <string>
#include <cstddef>
#include <cctype>
#include "iter.hpp"

// Function template to pass as pointers
template <class T>
void	print_it(const T& x)
{
	std::cout << x << ' ';
}

template <class T>
void	inc_it(T& x)
{
	++x;
}

// Non-template mutator for std::string
void	upcase_str(std::string& s)
{
	for (std::size_t i = 0; i < s.size(); ++i)
	{
		unsigned char ch = static_cast<unsigned char>(s[i]);
		s[i] = static_cast<char>(std::toupper(ch));
	}
}

template <class T>
void	show_array(const T* a, std::size_t n, const char* label)
{
	std::cout << label << " [ ";
	iter(a, n, &print_it<T>);
	std::cout << "]" << std::endl;
}

int main(void)
{
	// int (non-const) with mutating (read-only functions)
	int	ai[] = {1, 2, 3, 4};
	std::size_t ni = sizeof(ai) / sizeof(ai[0]);

	show_array(ai, ni, "ints before:");
	iter(ai, ni, &inc_it<int>);
	show_array(ai, ni, "ints after ++ :");
	std::cout << std::endl;

	// const int with read-only function
	const int ci[] = {5, 6, 7};
	std::size_t nci = sizeof(ci) / sizeof(ci[0]);

	std::cout << "const ints: [ ";
	iter(ci, nci, &print_it<int>);
	std::cout << "]\n" << std::endl;

	// std::string (non-const) with mutating (read-only functions)
	std::string ss[] = {"Mathys", "Marusya", "Charlie"};
	std::size_t ns = sizeof(ss) / sizeof(ss[0]);

	show_array(ss, ns, "string before:");
	iter(ss, ns, &upcase_str);
	show_array(ss, ns, "string upper :");
	std::cout << std::endl;

	// Edge cases: zero length and null pointer
	int* np = 0;
	iter(np, 0, &print_it<int>);

	return (0);
}

