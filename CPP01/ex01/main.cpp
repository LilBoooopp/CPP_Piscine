/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:33:16 by cbopp             #+#    #+#             */
/*   Updated: 2025/06/30 14:24:42 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

Zombie* zombieHorde(int N, std::string name);

int	main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <number_of_zombies> <name>" << std::endl;
		return (1);
	}

	int N = std::atoi(argv[1]);
	if (N <= 0) {
		std::cerr << "Number of zombies must be positive." << std::endl;
		return (1);
	}
	
	std::string name = argv[2];

	std::cout << "--- Creating Zombie Horde ---" << std::endl;
	Zombie* horde = zombieHorde(N, name);

	if (horde == NULL) {
		std::cerr << "Failed to create zombie horde." << std::endl;
		return (1);
	}

	std::cout << "\n--- Announcing Horde ---" << std::endl;
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	std::cout << "\n--- Destroying Horde ---" << std::endl;
	delete[] horde;

	std::cout << "\n---End of main ---" << std::endl;
	return (0);
}
