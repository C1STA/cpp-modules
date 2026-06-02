#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "BitcoinExchange.hpp"

static const std::string DB_FILE = "data.csv";

BitcoinExchange::BitcoinExchange() { loadDB(DB_FILE); }

BitcoinExchange::BitcoinExchange(std::string const& input)
{
  loadDB(DB_FILE);
  evaluate(input);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) : _db(other._db) {}

BitcoinExchange&  BitcoinExchange::operator=(BitcoinExchange const& other)
{
  if (this != &other)
    this->_db = other._db;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static int isvalid_year(std::string const& year)
{
  if (year.size() != 4)
    return 0;
  for (std::size_t i = 0; i < year.size(); ++i)
    if (!std::isdigit(year[i]))
      return 0;
  int const y = std::atoi(year.c_str());
  return y;
}

static int isvalid_month(std::string const& month)
{
  if (month.size() != 2)
    return 0;
  for (std::size_t i = 0; i < month.size(); ++i)
    if (!std::isdigit(month[i]))
      return 0;
  int const m = std::atoi(month.c_str());
  if (m < 1 || m > 12)
    return 0;
  return m;
}

static bool isvalid_day(int const year, int const month, std::string const& day)
{
  if (day.size() != 2)
    return false;
  for (std::size_t i = 0; i < day.size(); ++i)
    if (!std::isdigit(day[i]))
      return false;
  int const d = std::atoi(day.c_str());
  if (d < 1 || d > 31)
    return false;
  int const thirty_days_month[] = {4, 6, 9, 11};
  if (d == 31) {
    for (int i = 0; i < 4; ++i)
      if (month == thirty_days_month[i])
        return false;
  }
  if (month == 2) {
    if (d > 29)
      return false;
    if (d == 29) {
      if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        return false;
    }
  }
  return true;
}

static bool isvalid_date(std::string const& date)
{
  if (date.empty())
    return false;
  if (std::count(date.begin(), date.end(), '-') != 2)
    return false;
  std::size_t first  = date.find('-');
  std::size_t second = date.find('-', first + 1);

  int const year = isvalid_year(date.substr(0, first));
  if (!year)
    return false;
  int const month = isvalid_month(date.substr(first + 1, second - first - 1));
  if (!month)
    return false;
  if (!isvalid_day(year, month, date.substr(second + 1)))
    return false;
  return true;
}

static double isvalid_rate(std::string const& rate)
{
  char  *end;
  double value = std::strtod(rate.c_str(), &end);
  if (end == rate.c_str() || *end != '\0' || value < 0)
    return -1;

  return value;
}

void  BitcoinExchange::loadDB(std::string const& database)
{
    std::ifstream file(database.c_str());
    if (!file)
      throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
      throw std::runtime_error("Error: missing header in database.");

    while (std::getline(file, line))
    {
      if (line.empty() || (line.find_first_not_of(' ') == std::string::npos))
        continue ;
      std::size_t pos = line.find(',');
      if (pos == std::string::npos)
        throw std::runtime_error("Error: data in database not valid.");
      std::string const date = line.substr(0, pos);
      if (!isvalid_date(date))
        throw std::runtime_error("Error: data in database not valid.");
      std::string const rate = line.substr(pos + 1);
      double value = isvalid_rate(rate);
      if (value == -1)
        throw std::runtime_error("Error: data in database not valid.");
      _db[date] = value;
    }
}

static double isvalid_value(std::string const& v, std::string const& line)
{
  char  *end;
  double value = std::strtod(v.c_str(), &end);
  if (end == v.c_str() || *end != '\0')
    return std::cerr << "Error: bad input => " << line << std::endl, -1;
  if (value < 0)
    return std::cerr << "Error: not a positive number." << std::endl, -1;
  if (value > 1000)
    return std::cerr << "Error: too large a number." << std::endl, -1;
  return value;
}

double  BitcoinExchange::lookup(std::string const& date) const
{
  std::map<std::string, double>::const_iterator it = _db.upper_bound(date);

  if (it == _db.begin())
    return -1;
  return (--it)->second;
}

void  BitcoinExchange::evaluate(std::string const& input) const
{
  std::ifstream file(input.c_str());
  if (!file)
    throw std::runtime_error("Error: could not open file.");

  std::string line;
  std::getline(file, line);
  if (line.empty() || (line.find_first_not_of(' ') == std::string::npos))
    std::cerr << "Error: missing header." << std::endl;
  else if (line != "date | value")
    std::cerr << "Error: invalid header." << std::endl;

  while (std::getline(file, line))
  {
    if (line.empty() || (line.find_first_not_of(' ') == std::string::npos))
      continue ;
    std::size_t pos = line.find('|');
    if (pos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    std::string date = line.substr(0, pos);
    std::size_t start = date.find_first_not_of(' ');
    if (start == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    date = date.substr(start);
    date = date.substr(0, date.find_last_not_of(' ') + 1);
    if (!isvalid_date(date)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    std::string v = line.substr(pos + 1);
    start = v.find_first_not_of(' ');
    if (start == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    v = v.substr(start);
    v = v.substr(0, v.find_last_not_of(' ') + 1);
    double value = isvalid_value(v, line);
    if (value == -1) {
      continue ;
    }
    double rate_calcul = lookup(date);
    if (rate_calcul == -1) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue ;
    }
    std::cout << date << " => " << value << " = " << value * rate_calcul << std::endl;
  }
}
