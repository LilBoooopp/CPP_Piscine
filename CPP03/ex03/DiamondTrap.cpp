/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:08:37 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 19:21:38 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
		this->health = FragTrap::health;
		this->energy = ScavTrap::energy;
		this->attackDamage = FragTrap::attackDamage;
		std::cout << "DiamondTrap " << name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << name << " destructed." << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
