#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <sys/time.h>
#include <vector>

class PmergeMe {

private:
  std::deque<int>  _d;
  std::vector<int> _v;
  double           _elapsed;
  PmergeMe();
public:
  PmergeMe(std::vector<int>&);
  PmergeMe(std::deque<int>&);
  PmergeMe(PmergeMe const&);
  PmergeMe& operator=(PmergeMe const&);
  ~PmergeMe();

std::vector<int> const& get_vector()  const;
std::deque<int>  const& get_deque()   const;
double           get_elapsed() const;

template<typename T>
void  init_elems(T& container, std::size_t n,
  std::vector<typename T::iterator>& main,
  std::vector<std::pair<typename T::iterator, typename T::iterator> >& pend)
{
  typename  T::iterator it = container.begin();
  bool  first = true;

  for (; it < container.end(); it += 2 * n)
  {
    if (first) {
      main.push_back(it);
      first = false;
    }
    else if (it + n <= container.end())
      pend.push_back(std::make_pair(it, it + n));
    if (it + 2 * n <= container.end())
      main.push_back(it + n);
  }
}

template<typename Iterator>
void  binary_search(std::vector<Iterator>& main, std::size_t n,
                    typename std::vector<Iterator>::iterator end, Iterator toinsert)
{
  typename std::vector<Iterator>::iterator  lo = main.begin();
  typename std::vector<Iterator>::iterator  hi = end;
  typename std::vector<Iterator>::iterator  mid;

  while (lo < hi)
  {
    mid = lo + (hi - lo) / 2;
    if (*((*mid) + n - 1) < *(toinsert + n - 1))
      lo = mid + 1;
    else
      hi = mid;
  }
  main.insert(lo, toinsert);
}

template<typename T>
void  insert_elems(std::size_t n,
  std::vector<typename T::iterator>& main,
  std::vector<std::pair<typename T::iterator, typename T::iterator> >& pend)
{
  std::size_t jac_now = 3;
  std::size_t jac_pre = 1;
  while (!pend.empty())
  {
    if (jac_now > pend.size())
    {
      for (int i = pend.size() - 1; i >= (int)(jac_pre - 1); --i)
      {
        typename std::vector<typename T::iterator>::iterator bound = std::find(main.begin(), main.end(), pend[i].second);
        typename std::vector<typename T::iterator>::iterator bound_final = (bound != main.end()) ? bound + 1 : bound;
        binary_search(main, n, bound_final, pend[i].first);
      }
      return ;
    }
    for (std::size_t i = jac_now; i > jac_pre; --i)
    {
      typename std::vector<typename T::iterator>::iterator bound = std::find(main.begin(), main.end(), pend[i - 2].second);
      typename std::vector<typename T::iterator>::iterator bound_final = (bound != main.end()) ? bound + 1 : bound;
      binary_search(main, n, bound_final, pend[i - 2].first);
    }
    std::size_t jac_tmp = jac_now;
    jac_now = jac_now + 2 * jac_pre;
    jac_pre = jac_tmp;
  }
}

template<typename T>
void merge_sort(T& container, std::size_t n)
{
  struct timeval start, end;
  gettimeofday(&start, NULL);
  if (container.size() <= 1 || n < 1)
    return ;
  else if (n > container.size() / 2)
    return ;
  for (std::size_t i = n; i - 1 < container.size(); i += 2 * n)
  {
    if (i + n <= container.size() && container[i - 1] > container[i - 1 + n])
      std::swap_ranges(container.begin() + (i - n), container.begin() + i, container.begin() + i);
  }
  merge_sort(container, n * 2);
  std::vector<typename T::iterator> main;
  std::vector<std::pair<typename T::iterator, typename T::iterator> > pend;
  init_elems(container, n, main, pend);
  if (pend.empty())
    return ;
  insert_elems<T>(n, main, pend);
  T sorted;
  typename std::vector<typename T::iterator>::iterator it = main.begin();
  for (; it < main.end(); ++it)
    sorted.insert(sorted.end(), *it, *it + n);
  if (main.size() * n < container.size())
    sorted.insert(sorted.end(),
    container.begin() + main.size() * n,
    container.end());
  std::swap(container, sorted);
  gettimeofday(&end, NULL);
  _elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

template<typename T>
void  print(T const& container) const
{
  for (std::size_t i = 0; i < container.size(); ++i)
    std::cout << container[i] << (i + 1 != container.size() ? " " : "\n");
}
};

#endif