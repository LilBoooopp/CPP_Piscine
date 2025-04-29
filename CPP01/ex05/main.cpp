/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:51:57 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/17 02:55:25 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.cpp"

int main() {
	Harl harl;

	std::cout << "--- Testing DEBUG ---" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "--- Testing INFO ---" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "--- Testing WARNING ---" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "--- Testing ERROR ---" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "--- Testing Unknown ---" << std::endl;
	harl.complain("NO EXIST");
	std::cout << std::endl;

	return (0);
}
