#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ~ScalarConverter();

  enum LiteralType
  {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
  };

  static LiteralType  detectType(const std::string& s);

  static double  getPseudo(const std::string& s);

  static void printChar(double value);
  static void printInt(double value);
  static void printFloat(double value);
  static void printDouble(double value);
  static void printInvalid();

public:
  static void convert(const std::string& literal);
};

#endif