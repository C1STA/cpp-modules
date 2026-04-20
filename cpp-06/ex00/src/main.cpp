#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char**av)
{
  if(ac != 2)
  {
    std::cout << "Error" << std::endl << av[0] << ": accepts 1 arg, received " << ac - 1 << std::endl;
    return 1;
  }
  ScalarConverter::convert(av[1]);
  return 0;
}
