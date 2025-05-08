#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria default constructor called of type " << this->type << std::endl;
}


AMateria::AMateria(const AMateria &other) {
    std::cout << "AMateria copy constructor called." << std::endl;
    *this = other;
}


AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignment operator called." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return (*this);
}

AMateria::~AMateria(void) {
    std::cout << "AMateria destructor called for type " << this->type << std::endl;
}

std::string const & AMateria::getType() const {
	return (this->type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "AMateria " << this->type << " used on target" << std::endl;
}
