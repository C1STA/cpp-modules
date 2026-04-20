#include <cctype>
#include "ScalarConverter.hpp"

static bool isChar(const std::string& s)
{
  if (s.size() != 1)
    return false;

  unsigned char c = static_cast<unsigned char>(s[0]);

  if (!std::isprint(c))
    return false;

  if (std::isdigit(c))
    return false;

  return true;
}

static bool isInt(const std::string& s)
{
  if (s.empty())
    return false;

  std::size_t i = 0;

  if (s[i] == '-' || s[i] == '+')
  {
    if (s.size() == 1)
      return false;
    i++;
  }
  for (; i < s.size(); i++)
  {
    unsigned char c = static_cast<unsigned char>(s[i]);

    if (!std::isdigit(c))
      return false;
  }
  return true;
}

static bool isFloat(const std::string& s)
{
  if (s.empty())
    return false;

  if (s[s.size() - 1] != 'f')
    return false;

  size_t  i = 0;
  if (s[i] == '-' || s[i] == '+')
  {
    if (s.size() == 1)
      return false;
    i++;
  }

  int dot = 0;
  for (; i < s.size() - 1; i++)
  {
    if (s[i] == '.')
    {
      if (i == 0 || !std::isdigit(static_cast<unsigned char>(s[i - 1])))
        return false;
      if (!std::isdigit(static_cast<unsigned char>(s[i + 1])))
        return false;
      dot++;
      if (dot > 1)
        return false;
    }
    else if (!std::isdigit(static_cast<unsigned char>(s[i])))
      return false;
  }

  if (dot != 1)
    return false;

  return true;
}

static bool isDouble(const std::string& s)
{
  if (s.empty())
    return false;

  size_t  i = 0;
  if (s[i] == '-' || s[i] == '+')
  {
    if (s.size() == 1)
      return false;
    i++;
  }

  int dot = 0;
  for (; i < s.size(); i++)
  {
    if (s[i] == '.')
    {
      if (i == 0 || !std::isdigit(static_cast<unsigned char>(s[i - 1])))
        return false;
      if (i + 1 == s.size() || !std::isdigit(static_cast<unsigned char>(s[i + 1])))
        return false;
      dot++;
      if (dot > 1)
        return false;
    }
    else if (!std::isdigit(static_cast<unsigned char>(s[i])))
      return false;
  }

  if (dot != 1)
    return false;

  return true;
}

static bool isPseudo(const std::string& s)
{
  if (s == "nan" || s == "nanf")
    return true;
  if (s == "+inf" || s == "+inff")
    return true;
  if (s == "-inf" || s == "-inff")
    return true;

  return false;
}

ScalarConverter::LiteralType  ScalarConverter::detectType(const std::string& s)
{
  if (isPseudo(s))
    return TYPE_PSEUDO;

  if (isChar(s))
    return TYPE_CHAR;

  if (isInt(s))
    return TYPE_INT;
 
  if (isFloat(s))
    return TYPE_FLOAT;

  if (isDouble(s))
    return TYPE_DOUBLE;

  return TYPE_INVALID;
}
