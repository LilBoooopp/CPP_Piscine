/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:37:18 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/16 08:52:51 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string		name;
		Weapon&			weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void attack();
};

#endif
