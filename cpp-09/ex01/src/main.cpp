#include <exception>
#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
  if (ac != 2)
    return std::cerr << "Error" << std::endl << av[0] << ": accepts 1 arg, received " << ac - 1 << std::endl, 1;
  
  try {
    RPN rpn(av[1]);
  }
  catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
