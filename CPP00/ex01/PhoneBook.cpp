#include "PhoneBook.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	if (contactCount >= 8) {
		std::cout << "Phonebook is full. Replacing the oldest contact." << std::endl;
		contactCount = 0;
	}

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin >> std::ws, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin >> std::ws, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin >> std::ws, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin >> std::ws, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin >> std::ws, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "All fields must be non-empty. Contact not added." << std::endl;
		return ;
	}

	contacts[contactCount].setFirstName(firstName);
	contacts[contactCount].setLastName(lastName);
	contacts[contactCount].setNickname(nickname);
	contacts[contactCount].setPhoneNumber(phoneNumber);
	contacts[contactCount].setDarkestSecret(darkestSecret);
	contactCount++;
	std::cout << "Contact added." << std::endl;
}

void PhoneBook::searchContact() const {
	if (contactCount == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	displayAllContacts();

	std::cout << "Enter the index of the contact to display: ";
	int	index;
	while (!(std::cin >> index)) {
		std::cout << "Invalid input. Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (index >= 0 && index < contactCount) {
		std::cout << "First Name:	" << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name:	" << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname:	" << contacts[index].getNickname() << std::endl;
		std::cout << "PhoneNumber:	" << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	} else {
		std::cout << "Invalid index." << std::endl;
	}
}

void PhoneBook::displayAllContacts() const {
	std::cout << std::right << std::setw(10) << "Index" << "|"
			<< std::right << std::setw(10) << "FirstName" << "|"
			<< std::right << std::setw(10) << "Last Name" << "|"
			<< std::right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; ++i) {
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 10)
			lastName = lastName.substr(0,9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";

		std::cout << std::right << std::setw(10) << i << "|"
				<< std::right << std::setw(10) << firstName << "|"
				<< std::right << std::setw(10) << lastName << "|"
				<< std::right << std::setw(10) << nickname << std::endl;
	}
}

int PhoneBook::getContactCount() const {
	return contactCount;
}
