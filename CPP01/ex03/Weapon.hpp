/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:29:41 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/16 09:30:45 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string	type;
	
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType() const;
		void	setType(const std::string& newType);
};

#endif