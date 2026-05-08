#include <iostream>
#include <list>
#include "Span.hpp"

int main()
{
  {
    std::cout << "*** empty span ***" << std::endl;
    Span sp = Span();
    try { sp.addNumber(3); }
    catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
  }

  {
    std::cout << std::endl << "*** span with one element ***" << std::endl;
    Span sp = Span(1);
    sp.addNumber(11);
    try { sp.shortestSpan(); }
    catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
    try { sp.longestSpan(); }
    catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
  }

  {
    std::cout << std::endl << "*** span with 5 elements + 1***" << std::endl;
    Span sp = Span(5);
    sp.addNumber(3);
    sp.addNumber(33);
    sp.addNumber(44);
    sp.addNumber(0);
    sp.addNumber(7);

    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;

    try { sp.addNumber(12); }
    catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
  }

  {
    std::cout << std::endl << "*** filling span with a range of elements***" << std::endl;
    Span sp = Span(20000);

    sp.addNumber(4);
    sp.addNumber(44);

    std::list<int> l;
    for (int i = 0; i < 19999; i++)
      l.push_back(i);

    try {
      sp.addRange(l.begin(), l.end());
      std::cout << "Longest span: " << sp.longestSpan() << std::endl;
      std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
  }

  {
    std::cout << std::endl << "*** subject span***" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  return 0;
}
