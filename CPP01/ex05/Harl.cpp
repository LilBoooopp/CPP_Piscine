/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:39:42 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/17 02:51:44 by cbopp            ###   ########.fr       */
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
				<< "I think I deserve to have some extra bacon for free. "
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

	for (int i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			(this->*(functions[i]))();
			return ;
		}
	}

	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
