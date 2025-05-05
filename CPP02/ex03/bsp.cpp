/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:53:12 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 16:19:55 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateSide(Point const p1, Point const p2, Point const testPoint) {
	Fixed val = (p2.getX() - p1.getX()) * (testPoint.getY() - p1.getY()) -
				(p2.getY() - p1.getY()) * (testPoint.getX() - p1.getX());
    return (val);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed side1 = calculateSide(a, b, point);
    Fixed side2 = calculateSide(b, c, point);
    Fixed side3 = calculateSide(c, a, point);

	Fixed	zero(0);
	if (side1 == zero || side2 == zero || side3 == zero) {
		return (false);
	}

	bool	allPositive = (side1 > zero && side2 > zero && side3 > zero);
    bool	allNegative = (side1 < zero && side2 < zero && side3 < zero);

    return allPositive || allNegative;
}
