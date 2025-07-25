#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data {
	int			n;
	std::string	message;

	Data(int _n = 42, const std::string& m = "hello")
	 : n(_n), message(m) {}
};

std::ostream& operator<<(std::ostream& os, const Data& d);

#endif
