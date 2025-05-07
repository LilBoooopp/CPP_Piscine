/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:07:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 15:18:24 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Default Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal of type " << this->type << " was constructed." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal of type " << type << " was destroyed." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copied." << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::makeSound() const {
	std::cout << "Some generic animal sound..." << std::endl;
}
