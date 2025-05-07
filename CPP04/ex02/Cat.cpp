/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:23:32 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 21:47:14 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
	std::cout << "😺 Default cat constructor called" << std::endl;
	this->brain = new Brain();
	this->brain->ideas[0] = "Cat idea: Nap time!";
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << "😺 Cat copy constructor called" << std::endl;
	this->brain = new Brain(*(other.brain));
}

Cat	&Cat::operator=(const Cat &other) {
	std::cout << "😺 Cat assignment operator called" << std::endl;
	if (this != &other){
		AAnimal::operator=(other);

		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "😺 Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const {
	std::cout << "😺 Meow!" << std::endl;
}

void	Cat::showIdeas() const {
	if (this->brain && this->brain->ideas[0] != "") {
		std::cout << "Cat's first idea: " << this->brain->ideas[0] << std::endl;
	} else {
		std::cout << "Cat has no ideas or no brain!" << std::endl;
	}
}
