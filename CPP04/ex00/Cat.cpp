/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:23:32 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 15:30:16 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Dog") {
	std::cout << "😺 Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "😺 Cat copy constructor called" << std::endl;
	*this = other;
}

Cat	&Cat::operator=(const Cat &other) {
	std::cout << "😺 Cat assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "😺 Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "😺 Meow!" << std::endl;
}