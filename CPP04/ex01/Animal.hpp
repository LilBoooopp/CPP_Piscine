/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:38:58 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 21:26:01 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string	type;
	
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