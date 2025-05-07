/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:07:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 21:47:58 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Default Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "Animal of type " << this->type << " was constructed." << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal of type " << type << " was destroyed." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
	std::cout << "Animal copied." << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	AAnimal::getType() const {
	return (this->type);
}
