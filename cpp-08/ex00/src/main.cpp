#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
  int arr[] = {1, 2, 3, 4, 5};
  std::vector<int> const vec(arr, arr + 5);

  std::list<int> l(arr, arr + 5);


  try {
    int n = easyfind(vec, 4);
    std::cout << n << " is part of the container (vector)" << std::endl;

    n = easyfind(l, 2);
    std::cout << n << " is part of the container (list)" << std::endl;

    n = easyfind(l, 7);
  }
  catch (std::exception const&){
    std::cout << "Number not found" << std::endl;
  }
  return 0;
}
