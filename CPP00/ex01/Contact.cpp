/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:22:38 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/14 18:35:53 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

#include <iostream>

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
				std::string phoneNumber, std::string darkestSecret)
		: firstName(firstName),
		lastName(lastName),
		nickname(nickname),
		phoneNumber(phoneNumber),
		darkestSecret(darkestSecret) {}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::setFirstName(const std::string &firstName) {this->firstName = firstName; }
void Contact::setLastName(const std::string &lastName) {this->lastName = lastName; }
void Contact::setNickname(const std::string &nickname) {this->nickname = nickname; }
void Contact::setPhoneNumber(const std::string &phoneNumber) {this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string &darkestSecret) {this->darkestSecret = darkestSecret; }

bool Contact::isEmpty() const {
	return firstName.empty() && lastName.empty() && nickname.empty() && phoneNumber.empty() && darkestSecret.empty();
}
