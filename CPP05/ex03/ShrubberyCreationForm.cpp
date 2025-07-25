#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", 145, 137), _target(target) {
	//std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {
	//std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	//std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	//std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs) return ;
	ofs <<	"       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\\n";
	ofs.close();
}
