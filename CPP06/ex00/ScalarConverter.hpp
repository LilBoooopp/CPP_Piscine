#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter(void);
	
	static void convert(const double literal);
private:
	ScalarConverter(void);
};

#endif
