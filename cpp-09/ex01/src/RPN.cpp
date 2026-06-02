#include <cstdlib>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <limits>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const& expression) { evaluate(expression); }

RPN::RPN(RPN const& other) : _numbers(other._numbers) {}

RPN&  RPN::operator=(RPN const& other)
{
  if (this != &other)
    _numbers = other._numbers;
  return *this;
}

RPN::~RPN() {}

static int  calculate(int const a, int const b, std::string const& sign)
{
  long long result;

  if (sign == "+")
    result = static_cast<long long>(a) + b;
  else if (sign == "-")
    result = static_cast<long long>(a) - b;
  else if (sign == "/") {
    if (!b)
      throw std::runtime_error("Error");
    result = static_cast<long long>(a) / b;
  }
  else
    result = static_cast<long long>(a) * b;
  if (result < std::numeric_limits<int>::min() ||
      result > std::numeric_limits<int>::max())
      throw std::runtime_error("Error");
  return result;
}

void  RPN::evaluate(std::string const& expression)
{
  if (expression.empty())
    throw std::runtime_error("Error");

  std::istringstream iss(expression);
  std::string token;

  while (iss >> token)
  {
    if (token.size() == 1 && std::isdigit(token[0]))
      _numbers.push(token[0] - '0');
    else if (token == "+" || token == "-" || token == "/" || token == "*") {
      if (_numbers.size() < 2)
        throw std::runtime_error("Error");
      else {
        int b = _numbers.top();
        _numbers.pop();
        int a = _numbers.top();
        _numbers.pop();
        _numbers.push(calculate(a, b, token));
      }
    }
    else
      throw std::runtime_error("Error");
  }
  if (_numbers.empty() || _numbers.size() != 1)
    throw std::runtime_error("Error");
  std::cout << _numbers.top() << std::endl;
}
