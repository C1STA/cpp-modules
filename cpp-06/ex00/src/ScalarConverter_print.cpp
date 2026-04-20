#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include "ScalarConverter.hpp"

void  ScalarConverter::printChar(double value)
{
  std::cout << "char: ";

  if (std::isnan(value) || std::isinf(value))
  {
    std::cout << "impossible" << std::endl;
    return ;
  }
  if (value < 0 || value > 127)
  {
    std::cout << "impossible" << std::endl;
    return ;
  }

  char c = static_cast<char>(value);

  if (!std::isprint(static_cast<unsigned char>(c)))
  {
    std::cout << "Non displayable" << std::endl;
    return ;
  }

  std::cout << "'" << c << "'" << std::endl;
}

void  ScalarConverter::printInt(double value)
{
  std::cout << "int: ";

  if (std::isnan(value) || std::isinf(value))
  {
    std::cout << "impossible" << std::endl;
    return ;
  }
  if (value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
  {
    std::cout << "impossible" << std::endl;
    return ;
  }
  int i = static_cast<int>(value);
  std::cout << i << std::endl;
}

void  ScalarConverter::printFloat(double value)
{
  std::cout << "float: ";

  if (std::isnan(value))
  {
    std::cout << "nanf" << std::endl;
    return ;
  }
  if (std::isinf(value))
  {
    if (value < 0)
      std::cout << "-inff" << std::endl;
    else
      std::cout << "+inff" << std::endl;
    return ;
  }
  if (value > std::numeric_limits<float>::max() ||
      value < -std::numeric_limits<float>::max())
  {
    std::cout << "impossible" << std::endl;
    return ;
  }
  float f = static_cast<float>(value);
  if (f == std::floor(f))
  {
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);
  }
  else
    std::cout << f << "f" << std::endl;
}

void  ScalarConverter::printDouble(double value)
{
  std::cout << "double: ";

  if (std::isnan(value))
  {
    std::cout << "nan" << std::endl;
    return ;
  }
  if (std::isinf(value))
  {
    if (value < 0)
      std::cout << "-inf" << std::endl;
    else
      std::cout << "+inf" << std::endl;
    return ;
  }
  if (value == std::floor(value))
  {
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::setprecision(6);
  }
  else
    std::cout << value << std::endl;
}

void ScalarConverter::printInvalid()
{
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}
