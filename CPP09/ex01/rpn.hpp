#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>

class rpn {
public:
  rpn();
  rpn(const rpn &src);
  rpn &operator=(const rpn &src);
  ~rpn();

  static void calculate(std::string input);
};

#endif
