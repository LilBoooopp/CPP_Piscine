/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:47 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/15 13:32:41 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);

	Zombie* horde = reinterpret_cast<Zombie*>(new char[sizeof(Zombie) * N]);

	for (int i = 0; i < N; i++) {
		new (&horde[i]) Zombie(name);
	}

	return (horde);
}