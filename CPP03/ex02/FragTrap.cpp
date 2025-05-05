/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:58:16 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 19:04:16 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->health = 100;
	this->energy = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " has spawned" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests high fives!" << std::endl;
}