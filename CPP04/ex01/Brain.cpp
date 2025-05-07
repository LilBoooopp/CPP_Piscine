/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:20:50 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 21:25:30 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "An idea...";
	}
    std::cout << "Brain default constructor called." << std::endl;
}


Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}


Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called." << std::endl;
}
