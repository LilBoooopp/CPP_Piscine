/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:03:27 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/15 13:08:11 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	std::cout << "--- Creating Heap Zombie -- " << std::endl;
	Zombie* heap_zombie = newZombie("Heap");
	heap_zombie->announce();
	std::cout << "--- Deleting Heap Zombie ---" << std::endl;
	delete heap_zombie;
	std::cout << std::endl;

	std::cout << "--- Creating Stack Zombie ---" << std::endl;
	randomChump("Stack");
	std::cout<< "\n--- End of main ---" << std::endl;
	return (0);
}