#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
std::map<std::string, double> _db;

public:
  BitcoinExchange();
  BitcoinExchange(std::string const&);
  BitcoinExchange(BitcoinExchange const&);
  BitcoinExchange&  operator=(BitcoinExchange const&);
  ~BitcoinExchange();

  void loadDB(std::string const&);
  void evaluate(std::string const&) const;

  double  lookup(std::string const&) const;
};

#endif