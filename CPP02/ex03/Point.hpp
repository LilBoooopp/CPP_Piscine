/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:06 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 14:28:40 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point {
	private:
		const Fixed	x;
		const Fixed	y;
	
	public:
		Point(void);
		Point(const float fx, const float fy);
		Point(const Point &other);

		Point&	operator=(const Point &other);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif