/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:07:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/08/19 14:16:43 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Default Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal of type " << this->_type << " was constructed." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal of type " << _type << " was destroyed." << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << "Animal copied." << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	Animal::getType() const {
	return (this->_type);
}

void	Animal::makeSound() const {
	std::cout << "Some generic animal sound..." << std::endl;
}
