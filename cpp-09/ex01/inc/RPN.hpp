#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {

private:
  std::stack<int> _numbers;

public:
  RPN();
  RPN(std::string const&);
  RPN(RPN const&);
  RPN&  operator=(RPN const&);
  ~RPN();

  void  evaluate(std::string const&);
};

#endif