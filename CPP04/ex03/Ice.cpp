/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:03:34 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/08 14:58:25 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
    std::cout << "Ice default constructor called." << std::endl;
}


Ice::Ice(const Ice &other) : AMateria(other) {
    std::cout << "Ice copy constructor called." << std::endl;
    *this = other;
}


Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice assignment operator called." << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return (*this);
}

Ice::~Ice(void) {
    std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
