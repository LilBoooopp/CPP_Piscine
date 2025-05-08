/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:02:59 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/07 22:03:23 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        ~Ice(void);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
