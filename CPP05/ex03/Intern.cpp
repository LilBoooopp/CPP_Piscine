#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm* createShrub(const std::string& t) { return new ShrubberyCreationForm(t); }
static AForm* createRobot(const std::string& t) { return new RobotomyRequestForm(t); }
static AForm* createPardon(const std::string& t) { return new PresidentialPardonForm(t); }

Intern::Intern() {
	//std::cout << "Intern default constructor called." << std::endl;
}


Intern::Intern(const Intern &other) {
	//std::cout << "Intern copy constructor called." << std::endl;
	(void)other;
}


Intern &Intern::operator=(const Intern &other)
{
	//std::cout << "Intern assignment operator called." << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(void) {
	//std::cout << "Intern destructor called." << std::endl;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
	struct Mapping {
		const char* name;
		AForm*(*fn)(const std::string&);
	};
	static Mapping map[] = {
		{ "shrubbery creation", createShrub },
		{ "robotomy request", createRobot },
		{ "presidential pardon", createPardon }
	};
	for (size_t i = 0; i < sizeof(map)/sizeof(map[0]); ++i) {
		if (name == map[i].name) {
			std::cout << "Intern creates " << name << std::endl;
			return (map[i].fn(target));
		}
	}
	std::cout << "Intern couldn't find form named \"" << name << "\"" << std::endl;
	return (NULL);
}
