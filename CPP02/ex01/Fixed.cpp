/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:52:41 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/04 16:18:05 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = num << _fractionalBits;
}

Fixed::Fixed(const float fnum) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(fnum * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &outStream, const Fixed &fixedVal) {
	outStream << fixedVal.toFloat();
	return (outStream);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return (this->_fixedPointValue >> _fractionalBits);
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}
