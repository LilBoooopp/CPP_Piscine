#include "Human.hpp"

Human::Human() {
	//std::cout << "Human default constructor called." << std::endl;
}


Human::Human(const Human &other) {
	//std::cout << "Human copy constructor called." << std::endl;
	*this = other;
}


Human &Human::operator=(const Human &other)
{
	//std::cout << "Human assignment operator called." << std::endl;
	if (this != &other) {
		// assignment
	}
	return (*this);
}

Human::~Human(void) {
	//std::cout << "Human destructor called." << std::endl;
}
