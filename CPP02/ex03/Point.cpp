/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:25:35 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 16:21:05 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float fx, const float fy) : x(fx), y(fy) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point&	Point::operator=(const Point &other) {
	(void)other;
	return (*this);
}

Point::~Point(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX(void) const {
	return (this->x);
}

Fixed	Point::getY(void) const {
	return (this->y);
}
