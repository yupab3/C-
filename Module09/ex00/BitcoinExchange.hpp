#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cmath>
# include <vector>
# include <map>

class	BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange& operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void	printAmount(const char *file);
	void	parseMarket(const char *file);

private:
	std::map<std::string, float>	_market_data;
	float							_parsed_value;

	float	getMarketValue(std::string &date);
	void	checkMarketDate(std::string &date);
	void	checkMarketValue(std::string &value);
	bool	checkInputDate(std::string &date);
	bool	checkInputValue(std::string &value);
	bool	isLeapYear(int year);
	void	setDate(int i, int &year, int &month, int &day, std::string &date);
	};

#endif
