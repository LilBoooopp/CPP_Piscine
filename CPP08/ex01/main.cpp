#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int	main()
{
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
	}

	std::cout << "Basic errors" << std::endl;
	// too few elements
	try {
		Span s(1);
		s.addNumber(42);
		std::cout << s.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "caught: " << e.what() << std::endl;
	}

	// over capacity
	try {
		Span s(2);
		s.addNumber(1);
		s.addNumber(2);
		s.addNumber(3);
	} catch (const std::exception& e) {
		std::cout << "caught: " << e.what() << std::endl;
	}

	std::cout << "addRange with vector" << std::endl;
	{
		std::vector<int> v;
		for (int i = 0; i < 10; ++i) v.push_back(i * 5);

		Span s(static_cast<unsigned int>(v.size()));
		s.addRange(v.begin(), v.end());
		std::cout << "shortest = " << s.shortestSpan() << " (expect 5)" << std::endl;
		std::cout << "longest = " << s.longestSpan() << " (expect 45)" << std::endl;
	}

	std::cout << "addRange with list (duplicates allowed)" << std::endl;
	{
		std::list<int> L;
		L.push_back(7);
		L.push_back(3);
		L.push_back(7);
		L.push_back(12);

		Span s(static_cast<unsigned int>(L.size()));
		s.addRange(L.begin(), L.end());
		std::cout << "shortest = " << s.shortestSpan() << " (expecting 0 due to duplicates)" << std::endl;
		std::cout << "longest = " << s.longestSpan() << " (expect 12-3 = 9)" << std::endl;
	}

	std::cout << "large test" << std::endl;
	{
		const unsigned int N = 10000U;
		Span s(N);

		std::vector<int> mass;
		mass.reserve(N);
		std::srand(static_cast<unsigned int>(std::time(0)));
		for (unsigned int i = 0; i < N; ++i) {
			mass.push_back(std::rand() % 100000);
		}

		s.addRange(mass.begin(), mass.end());
		std::cout	<< "size = " << s.size()
					<< ", shortest = " << s.shortestSpan()
					<< ", longest = " << s.longestSpan()
					<< std::endl;
	}

	return (0);
}