#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{
public:
	Fixed(void);
	Fixed(const Fixed &_Fixed);
	Fixed&	operator=(const Fixed &_Fixed);
	~Fixed(void);
	
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int	Num;
	static const int	PosPoint = 8;
};

#endif