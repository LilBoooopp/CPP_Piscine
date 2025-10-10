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

	return (0);
}