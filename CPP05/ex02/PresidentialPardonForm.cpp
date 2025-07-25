#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardon", 25, 5), _target(target) {
	//std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {
	//std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	//std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	//std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void	PresidentialPardonForm::executeAction() const {
	std::cout << _target << " has been pardoned by Donald Trump the Wise." << std::endl;
}
