/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:52:21 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/15 13:59:55 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout	<< "--- Memory Addresses ---" << std::endl
				<< "Address of string: " << &str << std::endl
				<< "Address held by stringPTR: " << stringPTR << std::endl
				<< "Address held by stringREF: " << &stringREF << std::endl;
	
	std::cout	<< "--- Values ---" << std::endl
				<< "Value of str: " << str << std::endl
				<< "Value pointed to by stringPTR: " << *stringPTR << std::endl
				<< "Value pointed to by stringREF: " << stringREF << std::endl;
	
	std::cout << "\n--- End of main ---" << std::endl;
	return (0);
}