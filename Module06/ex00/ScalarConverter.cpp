#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>

static int	isNegativeInf(const std::string& _trgt)
{
	if (_trgt == "-inf" || _trgt == "-inff")
	{
		return true;
	}
	return false;
}

static int	isPositiveInf(const std::string& _trgt)
{
	if (_trgt == "+inf" || _trgt == "inf" || _trgt == "+inff" || _trgt == "inff"){
		return true;
	}
	return false;
}

static int	isNan(const std::string& _trgt)
{
	if (_trgt == "nan" || _trgt == "nanf")
	{
		return true;
	}
	return false;
}

static double	stob(const std::string& _trgt)
{
	double	tmp = 0;
	char	flagNegative = 1;
	double	flagDecimal = 0;

	if (_trgt[0] == '\'')
	{
		if (_trgt.size() != 3)
		{
			throw std::invalid_argument("\"wrong input\"");
		}
		return static_cast<double>(_trgt[1]);
	}
	else if (_trgt.find('f') != std::string::npos &&
		(_trgt.find('f') != _trgt.size() - 1 || _trgt.size() == 1 || _trgt.find('.') == std::string::npos))
	{
		throw std::invalid_argument("\"wrong input\"");
	}
	else if (_trgt.find('.') != std::string::npos &&
		(_trgt.rfind('.') != _trgt.find('.') || isdigit(_trgt[_trgt.find('.') + 1])) == 0)
	{
		throw std::invalid_argument("\"wrong input\"");
	}
	for (size_t i = 0; i < _trgt.size(); i++)
	{
		if (flagDecimal == 0)
		{
			if (i == 0 && _trgt[i] == '-')
			{
				flagNegative = -1;
			}
			else if (isdigit(_trgt[i]) == 0 && _trgt[i] != '.' && _trgt[i] != 'f')
			{
				throw std::invalid_argument("\"wrong input\"");
			}
			else if (_trgt[i] == '.')
			{
				flagDecimal = 1;
			}
			else if (_trgt[i] != 'f')
			{
				tmp = tmp * 10 + static_cast<double>(_trgt[i] - 48);
			}
		}
		else
		{
			if (isdigit(_trgt[i]) == 0 && _trgt[i] != 'f')
			{
				throw std::invalid_argument("\"wrong input\"");
			}
			else if (_trgt[i] != 'f')
			{
				flagDecimal = flagDecimal * 10;
				tmp = tmp + static_cast<double>(_trgt[i] - 48) / flagDecimal;
			}
		}
	}
	return flagNegative * tmp;
}

static void	assignWithCast(const double& _trgt, char& _c, int& _i, float& _f, double& _d)
{
	_c = static_cast<char>(_trgt);
	_i = static_cast<int>(_trgt);
	_f = static_cast<float>(_trgt);
	_d = _trgt;
}

static void	printVariables(const std::string& _trgt, const char& _c, const int& _i, const float& _f, const double& _d)
{
	size_t	zeroCount = 0;

	if (isNan(_trgt) || isPositiveInf(_trgt) || isNegativeInf(_trgt))
	{
		if (std::isprint(_c))
		{
			std::cout << "char : impossible, the casted result is \"" << _c << "\"\n";
		}
		else
		{
			std::cout << "char : impossible, the casted result is Non displayable" << "\n";
		}
		std::cout << "int : impossible, the casted result is \"" << _i << "\"\n";
		std::cout << "float : \"" << _f << "f\"\n";
		std::cout << "double : \"" << _d << "\"\n";
	}
	else{
		if (std::isprint(_c))
		{
			std::cout << "char : \"" << _c << "\"\n";
		}
		else
		{
			if (_d >= 128 || _d <= -129)
			{
				std::cout << "char : impossible - overflow" << '\n';
			}
			else
			{
				std::cout << "char : Non displayable" << '\n';
			}
		}
		if (_d >= 2147483648 || _d <= -2147483649)
		{
			std::cout << "int : impossible - overflow" << '\n';
		}
		else
		{
			std::cout << "int : \"" << _i << "\"\n";
		}
		while ((_trgt.find('.') != std::string::npos && _trgt.find('.') - zeroCount > 1 && _trgt.find('0', zeroCount) == zeroCount) ||
		(_trgt.find('.') == std::string::npos && _trgt.size() - zeroCount > 1 && _trgt.find('0', zeroCount) == zeroCount))
		{
			zeroCount++;
		}
		if (_trgt.find('\'') != std::string::npos)
		{
			std::cout.precision(_trgt.size() - zeroCount);
		}
		else if (_trgt.find('.') == std::string::npos)
		{
		
			if (_d < 0)
			{
				std::cout.precision(_trgt.size() - zeroCount);
			}
			else
			{
				std::cout.precision(_trgt.size() + 1 - zeroCount);
			}
		}
		else if (-1.0 < _d && _d < 1.0 && _d != 0)
		{
			if (_d < 0)
			{
				std::cout.precision(_trgt.find('.') - 1 - zeroCount);
			}
			else
			{
				std::cout.precision(_trgt.find('.') - zeroCount);
			}
		}
		else
		{
			if (_d < 0)
			{
				std::cout.precision(_trgt.find('.') - zeroCount);
			}
			else
			{
				std::cout.precision(_trgt.find('.') + 1 - zeroCount);
			}
		}
		std::cout << "float : \"" << std::showpoint << _f << "f\"\n";
		std::cout << "double : \"" << std::showpoint << _d << "\"\n";
	}
}

void ScalarConverter::convert(const std::string& _trgt)
{
	char	c;
	int		i;
	float	f;
	double	d;


	try
	{
		if (isPositiveInf(_trgt))
		{
			assignWithCast(HUGE_VAL, c, i, f, d);
			printVariables(_trgt, c, i, f, d);
		}
		else if (isNegativeInf(_trgt))
		{
			assignWithCast(-1 * HUGE_VAL, c, i, f, d);
			printVariables(_trgt, c, i, f, d);
		}
		else if (isNan(_trgt))
		{
			assignWithCast(NAN, c, i, f, d);
			printVariables(_trgt, c, i, f, d);
		}
		else
		{
			assignWithCast(stob(_trgt), c, i, f, d);
			printVariables(_trgt, c, i, f, d);
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Fail.. reason : " << e.what() << '\n';
	}
}
