#include "rpn.hpp"

rpn::rpn() {}
rpn::rpn(const rpn &src) { *this = src; }
rpn &rpn::operator=(const rpn &src) {
  (void)src;
  return (*this);
}
rpn::~rpn() {}

void rpn::calculate(std::string input) {
  std::stack<int, std::list<int> > stack;

  for (size_t i = 0; i < input.length(); i++) {
    if (input[i] == ' ')
      continue;

    if (isdigit(input[i])) {
      stack.push(input[i] - '0');
    } else {
      if (stack.size() < 2) {
        std::cout << "Error" << std::endl;
        return;
      }

      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();

      int result = 0;
      if (input[i] == '+')
        result = a + b;
      else if (input[i] == '-')
        result = a - b;
      else if (input[i] == '*')
        result = a * b;
      else if (input[i] == '/') {
        if (b == 0) {
          std::cout << "Error" << std::endl;
          return;
        }
        result = a / b;
      } else {
        std::cout << "Error" << std::endl;
        return;
      }
      stack.push(result);
    }
  }

  if (stack.size() != 1) {
    std::cout << "Error" << std::endl;
  } else {
    std::cout << stack.top() << std::endl;
  }
}
