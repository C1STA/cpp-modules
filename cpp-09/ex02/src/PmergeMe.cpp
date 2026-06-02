#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::deque<int>& d) : _d(d), _elapsed(0) { merge_sort(_d, 1); }

PmergeMe::PmergeMe(std::vector<int>& v) : _v(v), _elapsed(0) { merge_sort(_v, 1); }

PmergeMe::PmergeMe(PmergeMe const& other) : _d(other._d), _v(other._v), _elapsed(other._elapsed) {}

PmergeMe& PmergeMe::operator=(PmergeMe const& other)
{
  if (this != &other)
  {
    _d = other._d;
    _v = other._v;
    _elapsed = other._elapsed;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> const& PmergeMe::get_vector()  const { return _v; }

std::deque<int>  const& PmergeMe::get_deque()   const { return _d; }

double           PmergeMe::get_elapsed() const { return _elapsed; }
