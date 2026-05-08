#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <stdexcept>
#include <vector>

class Span {

private:
  std::vector<int>  _data;
  unsigned int      _N;

public:
  Span();
  Span(unsigned int);
  Span(Span const&);
  Span& operator=(Span const&);
  ~Span();

  void  addNumber(int const);

  int   shortestSpan();
  int   longestSpan();

  template<typename T>
  void addRange(T begin, T end)
  {
    if ((std::distance(begin, end) + _data.size()) > _N)
      throw std::runtime_error("Error: cannot add element(s), data would be more than full.");
    _data.insert(_data.end(), begin, end);
  }
};

#endif