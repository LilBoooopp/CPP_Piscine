/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:48:30 by cbopp             #+#    #+#             */
/*   Updated: 2025/06/30 23:16:22 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& newName) : name(newName), health(10), energy(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), health(other.health), energy(other.energy), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		health = other.health;
		energy = other.energy;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned!" <<std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energy > 0 && this->health > 0) {
		this->energy--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot attack! No energy or health left." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->health -= amount;
	if (health < 0)
		health = 0;
	std::cout << "ClapTrap " << name << " has taken " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy > 0 && this->health > 0) {
		this->energy--;
		std::cout << "ClapTrap " << name << " repaired " << amount << " health!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't repair. Not enough energy or health left!" << std::endl;
	}
}
