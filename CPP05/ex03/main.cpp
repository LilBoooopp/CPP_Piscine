/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:57:04 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/25 11:23:26 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	Intern	someIntern;
	Bureaucrat john("John", 42);

	AForm* f1 = someIntern.makeForm("robotomy request", "Marvin");
	AForm* f2 = someIntern.makeForm("unknown form", "Nobody");
	AForm* f3 = someIntern.makeForm("shrubbery creation", "Garden");

	if (f1) {
		john.signForm(*f1);
		john.executeForm(*f1);
		delete f1;
	}
	if (f2) {
		delete f2;
	}
	if (f3) {
		john.signForm(*f3);
		john.executeForm(*f3);
		delete f3;
	}
	
	return (0);
}