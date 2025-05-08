/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:58:04 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/08 14:58:11 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
    std::cout << "Cure default constructor called." << std::endl;
}


Cure::Cure(const Cure &other) : AMateria(other.type) {
    std::cout << "Cure copy constructor called." << std::endl;
    *this = other;
}


Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure assignment operator called." << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return (*this);
}

Cure::~Cure(void) {
    std::cout << "Cure destructor called." << std::endl;
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
