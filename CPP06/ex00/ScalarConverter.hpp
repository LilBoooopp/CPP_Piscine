#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);

		static void convert(const std::string& literal);
	private:
		static bool isChar	(const std::string&);
		static bool isInt	(const std::string&);
		static bool isFloat	(const std::string&);
		static bool isDouble(const std::string&);
		static bool isPseudo(const std::string&);

		static void printChar	(char c);
		static void printInt	(int i);
		static void printFloat	(float f);
		static void printDouble	(double d);
};

#endif
