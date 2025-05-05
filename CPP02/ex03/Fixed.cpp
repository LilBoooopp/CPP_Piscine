/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:52:41 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 16:10:55 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = num << _fractionalBits;
}

Fixed::Fixed(const float fnum) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(fnum * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) const {
	return (this->_fixedPointValue > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->_fixedPointValue < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->_fixedPointValue >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->_fixedPointValue <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->_fixedPointValue == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->_fixedPointValue != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed	result;

	result.setRawBits(this->_fixedPointValue + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed	result;

	result.setRawBits(this->_fixedPointValue - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed	result;

	long long	temp = (long long)this->_fixedPointValue * (long long)other.getRawBits();
	result.setRawBits(temp >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed	result;

	long long	temp = (long long)this->_fixedPointValue / (long long)other.getRawBits();
	result.setRawBits(temp >> _fractionalBits);
	return (result);
}

//	Preincrement
Fixed&	Fixed::operator++(void) {
	this->_fixedPointValue++;
	return (*this);
}

//	Postincrement
Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	++(*this); //uses preincrement
	return (temp);
}

Fixed&	Fixed::operator--(void) {
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	--(*this);
	return (temp);
}

std::ostream& operator<<(std::ostream &outStream, const Fixed &fixedVal) {
	outStream << fixedVal.toFloat();
	return (outStream);
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
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

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b); 
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}
