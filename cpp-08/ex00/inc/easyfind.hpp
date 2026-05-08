#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

template<typename T>
int easyfind(T const& container, int const tofind)
{
  typename T::const_iterator  it = std::find(container.begin(), container.end(), tofind);
  
  if (it == container.end())
    throw std::exception();

  return *it;
}

#endif