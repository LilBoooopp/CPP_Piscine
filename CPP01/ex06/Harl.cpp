/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:39:42 by cbopp             #+#    #+#             */
/*   Updated: 2025/06/30 14:50:27 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
	std::cout	<< "[DEBUG]" << std::endl
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup buger. "
				<< "I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout	<< "[INFO]" << std::endl
				<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout	<< "[WARNING]" << std::endl
				<< "I think I deserve to have some extra bacon for free. " << std::endl
				<< "I’ve been coming for years, "
				<< "whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
	std::cout	<< "[ERROR]" << std::endl
				<< "This is unacceptable! "
				<< "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	typedef void (Harl::*HarlMemberFunc)(void);

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	HarlMemberFunc functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4) {
		if (level == levels[i]) {
			break;
		}
		i++;
	}


	switch (i) {
		case (0):
			(this->*(functions[0]))();
			std::cout << std::endl;
			// fall through
		case (1):
			(this->*(functions[1]))();
			std::cout << std::endl;
			// fall through
		case (2):
			(this->*(functions[2]))();
			std::cout << std::endl;
			// fall through
		case (3):
			(this->*(functions[3]))();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
