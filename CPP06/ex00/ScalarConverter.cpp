#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <float.h>

static bool isCharLiteral(const std::string& s)
{
	if (s.size() == 1)
	{
		unsigned char c = static_cast<unsigned char>(s[0]);
		return (std::isprint(c) && !std::isdigit(c));
	}
	return (s.size() == 3 && s[0] == '\'' && s[2] == '\'' && std::isprint(static_cast<unsigned char>(s[1])));
}

static char charFrom(const std::string& s)
{
	return (s.size() == 1 ? s[0] : s[1]);
}

static bool isPseudo(const std::string& s, double& out)
{
	if (s == "nan" || s == "nanf")
	{
		out = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	if (s == "+inf" || s == "inf" || s == "+inff" || s == "inff")
	{
		out = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (s == "-inf" || s == "-inff")
	{
		out = -std::numeric_limits<double>::infinity();
		return (true);
	}
	return (false);
}

static bool parseDouble(const std::string& s, double& out)
{
	if (isPseudo(s, out))
		return (true);
	errno = 0;
	char* end = 0;
	const char* cstr = s.c_str();
	out = std::strtod(cstr, &end);
	if (end == cstr)
		return (false);
	if (*end == '\0')
		return (true);
	if (*end == 'f' && *(end + 1) == '\0')
		return (s.find('.') != std::string::npos);
	return (false);
}

static void	printAll(double d)
{
	std::cout << "char: ";
	if (!std::isfinite(d) || d < 0.0 || d > 127.0)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		unsigned char c = static_cast<unsigned char>(static_cast<int>(d));
		if (!std::isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
	}

	std::cout << "int: ";
	if (!std::isfinite(d) || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inff\n" : "-inff\n");
	else if (std::fabs(d) > static_cast<double>(FLT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf\n" : "-inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(const std::string& lit)
{
	if (isCharLiteral(lit)) {
		char c = charFrom(lit);
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: "    << static_cast<int>(c)    << "\n";
		std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(c)  << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
		return;
	}

	double d;
	if (!parseDouble(lit, d))
	{
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: impossible" << std::endl
					<< "double: impossible" << std::endl;
		return ;
	}
	printAll(d);
}
