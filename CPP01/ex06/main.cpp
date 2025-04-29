/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:51:57 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/17 03:18:36 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.cpp"

// int	getLevelCode(const std::string& level) {
// 	std::String	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	for (int i = 0; i < 4; ++i) {
// 		if (levels[i] == level) {
// 			return (i);
// 		}
// 	}
// 	return (-1);
// }

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
		return (1);
	}

	std::string level = argv[1];
	Harl		harl;
	// int 		minLevelCode = getLevelCode(level);

	// switch (minLevelCode) {
	// 	case (0):
	// 		harl.debug();
	// 		std::cout << std::endl;
	// 	case (1)
	// }
	
	harl.complain(level);

	return (0);
}
