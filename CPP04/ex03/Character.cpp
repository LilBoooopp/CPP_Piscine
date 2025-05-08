/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:08:31 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/08 15:09:17 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		this->inventory[i] = NULL;
	}
}


Character::Character(const Character &other) : name(other.name) {
	std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		this->inventory[i] = NULL;
	}
	*this = other;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		if (other.inventory[i]) {
			this->inventory[i] = other.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
}


Character &Character::operator=(const Character &other)
{
    std::cout << "Character assignment operator called." << std::endl;
    if (this != &other) {
        this->name = other.name;

		for (int i = 0; i < INVENTORY_SIZE; ++i) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}

		for (int i = 0; i < INVENTORY_SIZE; ++i) {
			if (other.inventory[i]) {
				this->inventory[i] = other.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
    }
    return (*this);
}

Character::~Character() {
    std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		delete this->inventory[i];
	}
}

std::string const & Character::getName() const {
	return (this->name);
}

void	Character::equip(AMateria* m) {
	if (!m) {
		std::cout << this->name << " tried to equip a NULL Materia." << std::endl;
		return ;
	}
	for (int i = 0; i < INVENTORY_SIZE; ++i) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			std::cout << this->name << " equipped " << m->getType() << " in slot " << i << "." << std::endl;
			return ;
		}
	}
	std::cout << this->name << "'s inventory is full. Cannot equip " << m->getType() << "." << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < INVENTORY_SIZE && this->inventory[idx] != NULL) {
		std::cout << this->name << " unequipped " << this->inventory[idx]->getType() << " from slot " << idx << std::endl;
		this->inventory[idx] = NULL;
	} else {
		std::cout << this->name << " tried to unequip from invalid or empty slot " << idx << "." << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < INVENTORY_SIZE && this->inventory[idx] != NULL) {
		std::cout << this->name << " uses Materia in slot " << idx << " on " << target.getName() << ": ";
		this->inventory[idx]->use(target);
	} else {
		std::cout << this->name << " tried to use Materia from invalid or empty slot " << idx << "." << std::endl;
	}
}
