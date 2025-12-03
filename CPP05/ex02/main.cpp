/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:57:04 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/25 11:06:17 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	Bureaucrat alice("Alice", 1);
	Bureaucrat bob  ("Bob", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm   robo("Bender");
	PresidentialPardonForm pardon("Arthur");

	bob.signForm(shrub);
	alice.signForm(shrub);
	bob.executeForm(shrub);
	alice.executeForm(shrub);

	alice.signForm(robo);
	alice.executeForm(robo);
	
	alice.signForm(pardon);
	alice.executeForm(pardon);

	return (0);
}
