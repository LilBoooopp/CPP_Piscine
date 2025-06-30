/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:59:41 by cbopp             #+#    #+#             */
/*   Updated: 2025/06/30 17:10:42 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) 
{
    Point a(1, 0);
    Point b(4.5, 0);
    Point c(2, -4);

    Point inside(2.5, -2.5);
    Point outside(0, 0);
    Point onEdge(2, 0);

    std::cout << "Expected inside : " << bsp(a,b,c,inside) << std::endl;
    std::cout << "Expected outside : " << bsp(a,b,c,outside) << std::endl;
    std::cout << "Expected outside : " << bsp(a,b,c,onEdge) << std::endl;
    std::cout << "Expected outside : " << bsp(a,b,c,a) << std::endl;
}