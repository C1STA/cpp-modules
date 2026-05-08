#include <algorithm>
#include <stdexcept>
#include <vector>
#include <limits>
#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(Span const& other) : _data(other._data), _N(other._N) {}

Span& Span::operator=(Span const& other)
{
  if (this != &other)
  {
    _data = other._data;
    _N = other._N;
  }
  return *this;
}

Span::~Span() {}

void  Span::addNumber(int const n)
{
  if (_data.size() >= _N)
    throw std::runtime_error("Error: cannot add element, data is full.");
  _data.push_back(n);
}

int   Span::shortestSpan()
{
  if (_data.size() <= 1)
    throw std::runtime_error("Error: unable to sort shortest span.");
  std::vector<int> tmp = _data;
  std::sort(tmp.begin(), tmp.end());
  long shortest = std::numeric_limits<long>::max();
  for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
  {
    if ((it + 1) != tmp.end())
    {
      if ((*(it + 1) - *it) < shortest)
        shortest = *(it + 1) - *it;
    }
    if (shortest == 0)
      break ;
  }
  return shortest;
}

int   Span::longestSpan()
{
  if (_data.size() <= 1)
    throw std::runtime_error("Error: unable to sort longest span.");
  return *std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end());
}
