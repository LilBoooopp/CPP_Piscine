/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:43:42 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 18:54:14 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->health = 100;
	this->energy = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (energy > 0 && health > 0) {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energy--;
	} else {
		std::cout << "ScavTrap " << name << " is too weak to attack." << std::endl;
	}
}
