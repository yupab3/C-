#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _parsed_value(0) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	this->_market_data = rhs._market_data;
	this->_parsed_value = rhs._parsed_value;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_market_data = rhs._market_data;
		this->_parsed_value = rhs._parsed_value;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::printAmount(const char *file)
{
	std::ifstream	filename(file);
	std::string		cur_line;

	if (filename.fail())
		throw std::logic_error("Error - stream fail [func. parseAmount]\n");
	std::getline(filename, cur_line);
	if (cur_line != "date | value")
	{
		filename.close();
		throw std::logic_error("Error - wrong head [func. parseAmount]\n");
	}
	while(std::getline(filename, cur_line))
	{
		size_t	pos = cur_line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cerr << "Error - bad input => \"" << cur_line << "\"\n";
			continue ;
		}
		std::string	date, value;
		date = cur_line.substr(0, pos);
		value = cur_line.substr(pos + 3);
		if (checkInputDate(date) == false)
		{
			std::cerr << "\"" << cur_line << "\"\n";
			continue ;
		}
		if (checkInputValue(value) == false)
		{
			std::cerr << "\"" << cur_line << "\"\n";
			continue ;
		}
		if (_market_data.upper_bound(date) == _market_data.begin())
			std::cerr << "Error - no data => \"" << cur_line << "\"\n";
		else
			 << date << " => " << value << " = " << _parsed_value * getMarketValue(date) << '\n';
	}
}

float	BitcoinExchange::getMarketValue(std::string &date)
{
	if (_market_data.upper_bound(date) == --_market_data.end())
		return (_market_data.upper_bound(date)->second);
	else
		return ((--_market_data.upper_bound(date))->second);
}

void	BitcoinExchange::parseMarket(const char *file)
{
	std::ifstream	filename(file);
	std::string		cur_line;

	if (filename.fail())
		throw std::logic_error("Error - stream fail [func. parseMarket]\n");
	std::getline(filename, cur_line);
	if (cur_line != "date,exchange_rate")
	{
		filename.close();
		throw std::logic_error("Error - wrong head [func. parseMarket]\n");
	}
	while(std::getline(filename, cur_line))
	{
		size_t	pos = cur_line.find(",");
		if (pos == std::string::npos)
		{
			filename.close();
			throw std::logic_error("Error - no delimiter => \"" + cur_line + "\" [func. parseMarket]\n");
		}
		std::string	date, value;
		date = cur_line.substr(0, pos);
		value = cur_line.substr(pos + 1);
		checkMarketDate(date);
		checkMarketValue(value);
		_market_data[date] = _parsed_value;
	}
}

void	BitcoinExchange::checkMarketDate(std::string &date)
{
	if (date.size() != 10)
		throw std::logic_error("Error - date size => \"" + date + "\" [func. checkMarketDate]\n");
	int	year = 0, month = 0, day = 0;
	for (int i = 0; i < 10; i++)
	{
		if ((i != 4 && i != 7) && !std::isdigit(date[i]))
			throw std::logic_error("Error - wrong char, expect num => \"" + date + "\" [func. checkMarketDate]\n");
		if ((i == 4 || i == 7) && date[i] != '-')
			throw std::logic_error("Error - wrong char, expect delim => \"" + date + "\" [func. checkMarketDate]\n");
		setDate(i, year, month, day, date);
	}
	if (month < 1 || month > 12)
		throw std::logic_error("Error - wrong month => \"" + date + "\" [func. checkMarketDate]\n");
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYoonSeokYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		throw std::logic_error("Error - wrong day => \"" + date + "\" [func. checkMarketDate]\n");
	if ((year == 2009 && month == 1 && day < 3) || year < 2009)
		throw std::logic_error("Error - The Times 03/Jan/2009 Chancellor on brink of second bailout for banks => \"" + date + "\" [func. checkMarketDate]\n");
}

void	BitcoinExchange::checkMarketValue(std::string &value)
{
	size_t	len = value.size();
	size_t	exp = 0;
	_parsed_value = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (exp != 0 && std::isdigit(value[i]))
		{
			_parsed_value += (value[i] - 48) / pow(10, exp);
			exp++;
		}
		else if (exp == 0 && i != 0 && value[i] == '.')
			exp = 1;
		else if (i > 0 && _parsed_value == 0 && exp == 0)
			throw std::logic_error("Error - multiple zeros => \"" + value + "\" [func. checkMarketValue]\n");
		else if (exp == 0 && std::isdigit(value[i]))
		{
			_parsed_value *= 10;
			_parsed_value += value[i] - 48;
		}
		else if (value[i] == '.')
			throw std::logic_error("Error - multiple dots => \"" + value + "\" [func. checkMarketValue]\n");
		else
			throw std::logic_error("Error - not a positive number => \"" + value + "\" [func. checkMarketValue]\n");
	}
}

bool	BitcoinExchange::checkInputDate(std::string &date)
{
	if (date.size() != 10)
	{
		std::cerr << "Error - date size => ";
		return (false);
	}
	int	year = 0, month = 0, day = 0;
	for (int i = 0; i < 10; i++)
	{
		if ((i != 4 && i != 7) && !std::isdigit(date[i]))
		{
			std::cerr << "Error - wrong char, expect num => ";
			return (false);
		}
		if ((i == 4 || i == 7) && date[i] != '-')
		{
			std::cerr << "Error - wrong char, expect delim => ";
			return (false);
		}
		setDate(i, year, month, day, date);
	}
	if (month < 1 || month > 12)
	{
		std::cerr << "Error - wrong month => ";
		return (false);
	}
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYoonSeokYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
	{
		std::cerr << "Error - wrong day ";
		if (isYoonSeokYear(year))
			std::cerr << "Yoon.. => ";
		else
			std::cerr << "=> ";
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkInputValue(std::string &value)
{
	size_t	len = value.size();
	size_t	exp = 0;

	if (value[0] == '\0')
	{
		std::cerr << "Error - empty field => ";
		return (false);
	}
	if (value[0] == '.')
	{
		std::cerr << "Error - wrong char => ";
		return (false);
	}
	_parsed_value = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (exp != 0 && std::isdigit(value[i]))
		{
			_parsed_value += (value[i] - 48) / pow(10, exp);
			exp++;
		}
		else if (i > 0 && _parsed_value == 0 && exp == 0)
		{
			std::cerr << "Error - multiple zeros => \"";
			return (false);
		}
		else if (exp == 0 && std::isdigit(value[i]))
		{
			_parsed_value *= 10;
			_parsed_value += value[i] - 48;
		}
		else if (exp == 0 && i != 0 && value[i] == '.')
			exp = 1;
		else if (value[i] == '.')
		{
			std::cerr << "Error - multiple dots => ";
			return (false);
		}
		else
		{
			std::cerr << "Error - not a positive number => ";
			return (false);
		}
		if (1000 < _parsed_value || (i > 3 && exp == 0) || (i > 3 && 1000 <= _parsed_value && value[i] != 48 && value[i] != '.'))
		{
			std::cerr << "Error - too large a number => ";
			return (false);
		}
	}
	if (value[len - 1] == '.')
	{
		std::cerr << "Error - wrong char => ";
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isYoonSeokYear(int year)
{
    // 윤년 확인 함수
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);
	if (year % 4 == 0)
		return (true);
	return (false);
}

void	BitcoinExchange::setDate(int i, int &year, int &month, int &day, std::string &date)
{
	if (i < 4)
		{
			year *= 10;
			year += date[i] - 48;
		}
		else if (i == 5 || i == 6)
		{
			month *= 10;
			month += date[i] - 48;
		}
		else if (i == 8 || i == 9)
		{
			day *= 10;
			day += date[i] - 48;
		}
}
