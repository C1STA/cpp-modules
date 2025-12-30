#include "Bureaucrat.hpp"

int main()
{
  try
  {
    Bureaucrat a("Alice", 2);
    std::cout << a << std::endl;
    a.promote();
    std::cout << "After promotion: " << a << std::endl;
    a.promote();
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try
  {
    Bureaucrat b("Bob", 149);
    std::cout << b << std::endl;
    b.demote();
    std::cout << "After demotion: " << b << std::endl;
    b.demote();
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  std::cout << std::endl;
  try
  {
    Bureaucrat c("Charles", 0);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Constructor exception: " << e.what() << std::endl;
  }
  return 0;
}
