/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:36:56 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/08 14:40:32 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

# define MAX_LEARNED_MATERIAS 4

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*learnMaterias[MAX_LEARNED_MATERIAS];
		int			numLearned;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource(void);

		void	learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif
