/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:38:37 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/08 14:48:56 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : numLearned(0) {
	std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < MAX_LEARNED_MATERIAS; ++i) {
		this->learnMaterias[i] = NULL;
	}
}


MateriaSource::MateriaSource(const MateriaSource &other) {
	//std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < MAX_LEARNED_MATERIAS; ++i) {
		this->learnMaterias[i] = NULL;
	}
	*this = other;
}


MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	//std::cout << "MateriaSource assignment operator called." << std::endl;
	if (this != &other) {
		for (int i = 0; i < numLearned; ++i) {
			delete this->learnMaterias[i];
			this->learnMaterias[i] = NULL;
		}
		this->numLearned = 0;

		for (int i = 0; i < MAX_LEARNED_MATERIAS; ++i) {
			if (other.learnMaterias[i])
			this->learnMateria(other.learnMaterias[i]->clone());
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	//std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < numLearned; ++i) {
		delete this->learnMaterias[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "MateriaSource cannot learn NULL Materia." << std::endl;
	}

	if (this->numLearned < MAX_LEARNED_MATERIAS) {
		this->learnMaterias[this->numLearned++] = m;
	} else {
		delete m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < numLearned; ++i) {
		if (this->learnMaterias[i] && this->learnMaterias[i]->getType() == type) {
			std::cout << "MateriaSource creating Materia of type " << type << std::endl;
			return (this->learnMaterias[i]->clone());
		}
	}
	std::cout << "MateriaSource does not know type " << type << std::endl;
	return (NULL);
}
