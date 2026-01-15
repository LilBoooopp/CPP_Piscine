#include "pmergeme.hpp"
#include <cctype>
#include <ctime>
#include <iomanip>

pmergeme::pmergeme() {}
pmergeme::pmergeme(const pmergeme &src) { *this = src; }
pmergeme &pmergeme::operator=(const pmergeme &src) {
  if (this != &src) {
    _vec = src._vec;
    _deq = src._deq;
  }
  return (*this);
}
pmergeme::~pmergeme() {}

static size_t getJacobsthal(size_t n) {
  if (n == 0)
    return (0);
  if (n == 1)
    return (1);
  size_t prev = 0;
  size_t curr = 1;
  for (size_t i = 2; i <= n; ++i) {
    size_t next = curr + 2 * prev;
    prev = curr;
    curr = next;
  }
  return (curr);
}

int pmergeme::binarySearchVector(const std::vector<int> &arr, int target,
                                 int limit) {
  int left = 0;
  int right = limit;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (left);
}

void pmergeme::sortVector(std::vector<int> &arr) {
  if (DEBUG == 1) {
    std::cout << "\n[Recursion Depth Input]: ";
    for (size_t i = 0; i < arr.size(); ++i)
    std::cout << arr[i] << " ";
    std::cout << std::endl;
  }
  if (arr.size() <= 1)
    return;

  bool hasStraggler = (arr.size() % 2 != 0);
  int straggler = 0;
  if (hasStraggler) {
    straggler = arr.back();
    arr.pop_back();
    if (DEBUG == 1) 
      std::cout << " -> Straggler detected: " << straggler << std::endl;
  }

  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i < arr.size(); i += 2) {
    if (arr[i] > arr[i + 1])
      pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    else
      pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
  }

  if (DEBUG == 1) {
    std::cout << " -> Pairs created (a > b) : ";
    for (size_t i = 0; i < pairs.size(); ++i)
    std::cout << "[" << pairs[i].first << "," << pairs[i].second << "] ";
    std::cout << std::endl;
  }

  std::vector<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i) {
    mainChain.push_back(pairs[i].first);
  }

  if (DEBUG == 1) {
  std::cout << " -> Recursive sortin Main chain (a's): ";
  for (size_t i = 0; i < mainChain.size(); ++i)
   std::cout << mainChain[i] << " ";
  std::cout << std::endl;
  }

  sortVector(mainChain);

  if (DEBUG == 1) {
    std::cout << " <- Returned from recursion. Sorted Main chain is now: ";
    for (size_t i = 0; i < mainChain.size(); ++i)
    std::cout << mainChain[i] << " ";
    std::cout << std::endl;
  }

  std::vector<int> result = mainChain;
  std::vector<int> pendingB;

  for (size_t i = 0; i < result.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (pairs[j].first == result[i]) {
        pendingB.push_back(pairs[j].second);
        pairs.erase(pairs.begin() + j);
        break;
      }
    }
  }

  if (DEBUG == 1) {
    std::cout << " -> Pending 'b' elements (matched to srted 'a's): ";
    for (size_t i = 0; i < pendingB.size(); ++i)
    std::cout << pendingB[i] << " ";
    std::cout << std::endl;
  }

  result.insert(result.begin(), pendingB[0]);

  size_t n_b = pendingB.size();
  size_t jacob_idx = 3;
  size_t inserted_count = 1;

  while (inserted_count < n_b) {
    size_t prev_jacob = getJacobsthal(jacob_idx - 1);
    size_t curr_jacob = getJacobsthal(jacob_idx);

    size_t limit = curr_jacob;
    if (limit > n_b)
      limit = n_b;

    for (size_t i = limit; i > prev_jacob; --i) {
      int val = pendingB[i - 1];
      int pos = binarySearchVector(result, val, result.size() - 1);
      result.insert(result.begin() + pos, val);
      inserted_count++;
    }
    jacob_idx++;
  }

  if (hasStraggler) {
    if (DEBUG == 1) 
      std::cout << " -> Inserting Straggler: " << straggler << std::endl;
    int pos = binarySearchVector(result, straggler, result.size() - 1);
    result.insert(result.begin() + pos, straggler);
  }

  arr = result;

  if (DEBUG == 1) {
    std::cout << "[End of Recursion Level]\nFinal Sorted: ";
    for (size_t i = 0; i < arr.size(); ++i)
    std::cout << arr[i] << " ";
    std::cout << std::endl;
  }
}

int pmergeme::binarySearchDeque(const std::deque<int>& arr, int target, int limit) {
  int left = 0;
  int right = limit;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (left);
}

void pmergeme::sortDeque(std::deque<int>& arr) {
  if (arr.size() <= 1)
    return;

  bool hasStraggler = (arr.size() % 2 != 0);
  int straggler = 0;
  if (hasStraggler) {
    straggler = arr.back();
    arr.pop_back();
  }

  std::deque<std::pair<int, int> > pairs;
  for (size_t i = 0; i < arr.size(); i += 2) {
    if (arr[i] > arr[i + 1])
      pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    else
      pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
  }

  std::deque<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i) {
    mainChain.push_back(pairs[i].first);
  }

  sortDeque(mainChain);

  std::deque<int> result = mainChain;
  std::deque<int> pendingB;

  for (size_t i = 0; i < result.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (pairs[j].first == result[i]) {
        pendingB.push_back(pairs[j].second);
        pairs.erase(pairs.begin() + j);
        break;
      }
    }
  }

  result.push_front(pendingB[0]);

  size_t n_b = pendingB.size();
  size_t jacob_idx = 3;
  size_t inserted_count = 1;

  while (inserted_count < n_b) {
    size_t prev_jacob = getJacobsthal(jacob_idx - 1);
    size_t curr_jacob = getJacobsthal(jacob_idx);

    size_t limit = curr_jacob;
    if (limit > n_b)
      limit = n_b;

    for (size_t i = limit; i > prev_jacob; --i) {
      int val = pendingB[i - 1];
      int pos = binarySearchDeque(result, val, result.size() - 1);
      result.insert(result.begin() + pos, val);
      inserted_count++;
    } 
    jacob_idx++;
  }

  if (hasStraggler) {
    int pos = binarySearchDeque(result, straggler, result.size() - 1);
    result.insert(result.begin() + pos, straggler);
  }

  arr = result;
}

void pmergeme::run(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::string s = argv[i];
    for (size_t j = 0; j < s.length(); ++j) {
      if (!isdigit(s[j])) {
        std::cout << "Error" << std::endl;
        return;
      }
    }
    long val = atol(s.c_str());
    if (val < 0 || val > INT_MAX) {
      std::cout << "Error" << std::endl;
      return;
    }
    _vec.push_back(static_cast<int>(val));
    _deq.push_back(static_cast<int>(val));
  }

  std::cout << "Before: ";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << _vec[i] << " ";
    if (i > 4) {
      std::cout << "[...]";
      break;
    }
  }
  std::cout << std::endl;

  clock_t start_vec = clock();
  sortVector(_vec);
  clock_t end_vec = clock();
  double time_vec = double(end_vec - start_vec) / CLOCKS_PER_SEC;

  clock_t start_deq = clock();
  sortDeque(_deq);
  clock_t end_deq = clock();
  double time_deq = double(end_deq - start_deq) / CLOCKS_PER_SEC;

  std::cout << "After: ";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << _vec[i] << " ";
    if (i > 4) {
      std::cout << "[...]";
      break;
    }
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5) << time_vec << " us" << std::endl;

  std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(5) << time_deq << " us" << std::endl;
}
