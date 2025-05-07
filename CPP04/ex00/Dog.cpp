/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:19:12 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 15:30:38 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "🐶 Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "🐶 Dog copy constructor called" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other) {
	std::cout << "🐶 Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "🐶 Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "🐶 Woof Woof!" << std::endl;
}