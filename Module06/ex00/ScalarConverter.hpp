#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter{
public:
	static void convert(const std::string& _trgt);
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& _copy);
	ScalarConverter& operator=(const ScalarConverter& _copy);
	~ScalarConverter(void);
};

#endif
