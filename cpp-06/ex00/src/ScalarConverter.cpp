#include <cstdlib>
#include <limits>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

ScalarConverter::~ScalarConverter() {}

double  ScalarConverter::getPseudo(const std::string& s)
{
  if (s == "nan" || s == "nanf") {
    return std::numeric_limits<double>::quiet_NaN();
  }
  else if (s[0] == '-') {
    return -std::numeric_limits<double>::infinity();
  }
  else {
    return std::numeric_limits<double>::infinity();
  }
}

void  ScalarConverter::convert(const std::string& literal)
{
  LiteralType type = detectType(literal);

  double  value = 0.0;

  switch (type)
  {
    case TYPE_CHAR:
      value = static_cast<double>(literal[0]);
      break ;
    case TYPE_INT:
      value = std::strtod(literal.c_str(), NULL);
      break ;
    case TYPE_FLOAT:
      value = std::strtod(literal.c_str(), NULL);
      break ;
    case TYPE_DOUBLE:
      value = std::strtod(literal.c_str(), NULL);
      break ;
    case TYPE_PSEUDO:
      value = getPseudo(literal);
      break ;
    case TYPE_INVALID:
    default:
      printInvalid();
      return ;
  }
  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}
