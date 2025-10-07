#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(const double lit)
{
	if (lit < std::numeric_limits<double>::max())
	{
		std::cout << "test" << std::endl;
	}
}
