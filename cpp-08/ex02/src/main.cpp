#include <iostream>
#include "MutantStack.hpp"

int main()
{
  std::cout << "***subject stack**" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);

  std::cout << "***const stack**" << std::endl;

    MutantStack<int> const ms(mstack);

    MutantStack<int>::const_iterator itc = ms.begin();
    MutantStack<int>::const_iterator itce = ms.end();

    for (; itc != itce; ++itc)
      std::cout << *itc << " (const iterator)" << std::endl;

  std::cout << "**string stack***" << std::endl;
  {
    MutantStack<std::string> mss;

    mss.push("Hello");
    mss.push("World");
    mss.push("42");

    MutantStack<std::string>::iterator it = mss.begin();
    MutantStack<std::string>::iterator ite = mss.end();

    for (; it != ite; ++it)
    {
      if (*it == "Hello")
        *it = "Good Bye";
      std::cout << *it << std::endl;
    }
  }
return 0;
}
