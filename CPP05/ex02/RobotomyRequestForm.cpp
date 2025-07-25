#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", 72, 45), _target(target) {
	//std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {
	//std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	//std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	//std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void	RobotomyRequestForm::executeAction() const {
	static bool	seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	std::cout << "Bzzzz... drilling noises..." << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}
