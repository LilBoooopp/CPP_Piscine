/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:19:12 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 21:29:59 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "🐶 Dog constructor called" << std::endl;
	this->brain = new Brain();
	this->brain->ideas[0] = "Dog idea: Chase ball!";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "🐶 Dog copy constructor called (deep copy)" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Dog	&Dog::operator=(const Dog &other) {
	std::cout << "🐶 Dog assignment operator called (deep copy)" << std::endl;
	if (this != &other) {
		Animal::operator=(other);

		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "🐶 Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const {
	std::cout << "🐶 Woof Woof!" << std::endl;
}

void	Dog::showIdeas() const {
	if (this->brain && this->brain->ideas[0] != "") {
		std::cout << "Dog's first idea: " << this->brain->ideas[0] << std::endl;
	} else {
		std::cout << "Dog has no ideas or no brain!" << std::endl;
	}
}