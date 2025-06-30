#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>

class Human {
	private:
		
	public:
		Human(void);
		Human(const Human &other);
		Human &operator=(const Human &other);
		~Human(void);
};

#endif
