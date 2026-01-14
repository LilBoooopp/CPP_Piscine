#include "pmergeme.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error" << std::endl;
    return (1);
  }

  pmergeme sorter;
  sorter.run(argc, argv);

  return (0);
}
