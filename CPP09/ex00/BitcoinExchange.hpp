#pragma once

#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange {
private:
	std::map<std::string, float> _database;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	void	loadDatabase(const char* filename);
	void	processInput(const char* filename);

	bool	isValidDate(const std::string& date) const;
	bool	isValidValue(const std::string& valueStr, float& value) const;
	float	getExchangeRate(const std::string& date);
};

