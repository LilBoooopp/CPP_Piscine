/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:52:17 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/08 00:54:23 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << '\n';
		a.increment();
		std::cout << a << '\n';
		a.increment();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	try {
		Bureaucrat b("Bob", 151);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	return (0);
}