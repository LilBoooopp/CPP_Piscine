#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src) {
		this->_database = src._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::isValidDate(const std::string& date ) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int	year, month, day;

	char	dash1, dash2;
	std::stringstream ss(date);

	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
	char* end;
	value = std::strtof(valueStr.c_str(), &end);
	
	if (valueStr.empty() || *end != '\0')
		return (false);
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::loadDatabase(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t delimiterPos = line.find(',');
		if (delimiterPos == std::string::npos)
			continue;

		std::string date = line.substr(0, delimiterPos);
		std::string rateStr = line.substr(delimiterPos + 1);

		float rate = static_cast<float>(std::atof(rateStr.c_str()));
		_database[date] = rate;
	}
	file.close();
}

float	BitcoinExchange::getExchangeRate(const std::string& date) {
	std::map<std::string, float>::iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return (it->second);

	if (it == _database.begin())
		return (0.0f);

	--it;
	return (it->second);
}

void	BitcoinExchange::processInput(const char* filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		size_t delimiterPos = line.find('|');
		if (delimiterPos == std::string::npos) {
			std::cerr << "Error: bad input -> " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delimiterPos);
		if (!date.empty() && date[date.length() - 1] == ' ')
			date.erase(date.length() - 1);

		std::string valueStr = line.substr(delimiterPos + 1);
		if (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input -> " << date << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value))
			continue;

		float rate = getExchangeRate(date);
		std::cout << date << " -> " << value << " = " << (value * rate) << std::endl;
	}
}

