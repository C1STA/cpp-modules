#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{ 
  int n = std::rand() % 3;

  if (n == 0) {
    return new A;
  }
  else if (n == 1) {
    return new B;
  }
  return new C;
}

void  identify(Base* p)
{
  std::cout << "object pointed:    ";

  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  }
  else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  }
  else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  }
  else {
    std::cout << "unable to identify object" << std::endl;
  }
}

void  identify(Base& p)
{
  std::cout << "object referenced: ";

  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    return ;
  } catch (...) {}

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    return ;
  } catch (...) {}

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    return ;
  } catch (...) {}

  std::cout << "unable to identify object" << std::endl;
}

int main(void)
{
  std::srand(std::time(0));

  std::cout << std::endl;
  for (int i = 0; i < 5; ++i)
  {
    Base* p = generate();
    identify(p);
    identify(*p);
    std::cout << std::endl;
    delete p;
  }

  return 0;
}
