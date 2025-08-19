/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:38:58 by cbopp             #+#    #+#             */
/*   Updated: 2025/08/19 14:16:22 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string	_type;
	
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal(void);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif