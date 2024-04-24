#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{
private:
	int	Num;
	static const int	PosPoint = 8;
public:
	Fixed(void);
	Fixed(const int _Num);
	Fixed(Fixed& _Fixed);
	Fixed&	operator=(const Fixed &_Fixed);
	~Fixed(void);
	
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif