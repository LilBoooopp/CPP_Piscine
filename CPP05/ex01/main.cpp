/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:57:04 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/25 10:31:06 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat alice("Alice", 50);
	Form tax("Taxform", 45, 30);

	std::cout << alice << std::endl;
	std::cout << tax << std::endl;

	alice.signForm(tax);
	std::cout << tax << std::endl;

	Bureaucrat bob("Bob", 100);
	bob.signForm(tax);

	try {
		Form bad("Bad", 0, 10);
	} catch (std::exception& e) {
		std::cerr << "Invalid form: " << e.what() << std::endl;
	}

	return (0);
}