#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) {	return (*this); }
ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(const std::string& lit) {
	if (isPseudo(lit)) {
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl;
		bool isFloatPseudo = (lit == "nanf" || lit == "+inff" || lit == "-inff");
		bool isDoublePseudo = (lit == "nan" || lit == "+inf" || lit == "-inf");
		if (isFloatPseudo) {
			std::cout << "float: " << lit << std::endl;
		} else {
			std::cout << "float: " << lit << "f" << std::endl;
		}

		if (isDoublePseudo) {
			std::cout << "double: " << lit << std::endl;
		} else {
			std::cout << "double: " << lit.substr(0, lit.size() - 1) << std::endl;
		}
		return ;
	}
	try {
		if (isChar(lit)) {
			char c = lit[1];
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
		}
		else if (isInt(lit)) {
			int i;
			std::stringstream(lit) >> i;
			printChar (static_cast<char>(i));
			printInt(i);
			printFloat(static_cast<float>(i));
			printDouble(static_cast<double>(i));
		}
		else if (isFloat(lit)) {
			std::string core = lit.substr(0, lit.size() - 1);
			std::stringstream ss(core);
			float f;
			if ((ss >> f).fail())
				throw std::invalid_argument("bad float literal");
			printChar(static_cast<char>(f));
			printInt(static_cast<int>(f));
			printFloat(f);
			printDouble(static_cast<double>(f));
		}
		else if (isDouble(lit)) {
			std::stringstream ss(lit);
			double d;
			if ((ss >> d).fail())
				throw std::invalid_argument("bad double literal");
			printChar(static_cast<char>(d));
			printInt(static_cast<int>(d));
			printFloat(static_cast<float>(d));
			printDouble(d);
		}
		else {
			throw std::invalid_argument("not a literal");
		}
	} catch (...) {
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: imposible" << std::endl
					<< "double: impossible" << std::endl;
	}
}

bool	ScalarConverter::isChar(const std::string& s) {
	return (s.size() == 3 && s[0] == '\'' && s[2] == '\'');
}

bool	ScalarConverter::isInt(const std::string& s) {
	std::istringstream ss(s);
	int i;
	char c;
	return (!(ss >> i).fail() && (ss >> c).fail());
}

bool	ScalarConverter::isFloat(const std::string& s) {
	if (s.size() < 2 || s[s.size() - 1] != 'f') return (false);
	std::string core = s.substr(0, s.size() - 1);
	std::istringstream ss(core);
	float f;
	char c;
	return (!(ss >> f).fail() && (ss >> c).fail());
}

bool	ScalarConverter::isDouble(const std::string& s) {
	std::istringstream ss(s);
	double d;
	char c;
	return (!(ss >> d).fail() && (ss >> c).fail());
}

bool	ScalarConverter::isPseudo(const std::string& s) {
	return (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff");
}

void	ScalarConverter::printChar(char c) {
	std::cout << "char: ";
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' << c << '\'' << std::endl;
}

void	ScalarConverter::printInt(int i) {
	std::cout << "int: ";
	if (i > std::numeric_limits<int>::max() ||
		i < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void	ScalarConverter::printFloat(float f) {
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
	else {
		std::cout	<< std::fixed << std::setprecision(1)
					<< f << "f" << std::endl
					<< std::resetiosflags(std::ios::fixed);
	}
}

void	ScalarConverter::printDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
	else {
		std::cout	<< std::fixed << std::setprecision(1)
					<< d << std::endl
					<< std::resetiosflags(std::ios::fixed);
	}
}
