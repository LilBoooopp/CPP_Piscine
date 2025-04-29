/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:43:05 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/14 18:36:34 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
	private:
		Contact	contacts[8];
		int		contactCount;
	
	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact() const;
		void	displayAllContacts() const;
		int		getContactCount() const;
};

#endif