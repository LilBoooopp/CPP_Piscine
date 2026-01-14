#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class pmergeme {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;

  void sortVector(std::vector<int> &arr);
  int binarySearchVector(const std::vector<int> &arr, int target, int limit);

  void sortDeque(std::deque<int> &arr);
  int binarySearchDeque(const std::deque<int> &arr, int target, int limit);

public:
  pmergeme();
  pmergeme(const pmergeme &src);
  pmergeme &operator=(const pmergeme &src);
  ~pmergeme();

  void run(int argc, char **argv);
};

#endif
