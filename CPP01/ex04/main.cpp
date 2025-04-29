/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:17:48 by cbopp             #+#    #+#             */
/*   Updated: 2025/04/17 02:28:25 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty() || s1.empty()) {
		std::cerr << "Error: Filename and string s1 cannot be empty." << std::endl;
		return (1);
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open input file '" << filename << "'" << std::endl;
		return (1);
	}

	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create output file '" << outputFilename << "'" << std::endl;
		inputFile.close();
		return (1);
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t	startPos = 0;
		size_t	foundPos = line.find(s1, startPos);

		while (foundPos != std::string::npos) { 
			outputFile << line.substr(startPos, foundPos - startPos);
			outputFile << s2;
			startPos = foundPos + s1.length();
			foundPos = line.find(s1, startPos);
		}
		outputFile << line.substr(startPos);

		if (!inputFile.eof()) {
			outputFile << std::endl;
		}
	}

	inputFile.close();
	outputFile.close();
	std::cout << "File processed successfully. Output written to '" << outputFilename << "'" << std::endl;
}
