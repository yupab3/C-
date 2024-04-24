#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{
private:
	int	Num;
	static const int	PosPoint = 8;
public:
	Fixed(void);
	Fixed(const int _Num);
	Fixed(const float _float);
	Fixed(const Fixed& _Fixed);
	Fixed&	operator=(const Fixed &_Fixed);
	~Fixed(void);
	
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& _Fixed);

#endif