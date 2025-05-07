/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:13:18 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 17:03:08 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void);
		
		void	makeSound() const;

};

#endif