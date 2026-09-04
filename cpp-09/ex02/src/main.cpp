#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <limits>
#include <stdexcept>
#include "PmergeMe.hpp"

template<typename T>
T  init_array(int ac, char **av)
{
  T container;
  for (int i = 1; i < ac; ++i)
  {
    char  *end;
    long long  n = std::strtol(av[i], &end, 10);
    if (end == av[i] || *end != '\0' || n <= 0 ||
      n > std::numeric_limits<int>::max())
      throw std::runtime_error("Error");
    container.push_back(n);
  }
  return container;
}

int main(int ac, char **av)
{

  if (ac < 2)
    return std::cerr << "Error" << std::endl << av[0] << ": accepts at least 1 arg, received " << ac - 1 << std::endl, 1;

  try {
    std::vector<int>  v = init_array<std::vector<int> >(ac, av);
    std::deque<int>  d(v.begin(), v.end());
    std::cout << "Before: ";
    for (std::size_t i = 0; i < v.size(); ++i)
      std::cout << v[i] << (i + 1 != v.size() ? " " : "\n");
    PmergeMe a(v);
    PmergeMe b(d);
    std::cout << "After:  ";
    a.print(a.get_vector());
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << a.get_elapsed() << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque  : " << b.get_elapsed() << " us" << std::endl;
  }
  catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
