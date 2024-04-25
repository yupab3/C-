#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{
public:
	Fixed(void);
	Fixed(const int _Num);
	Fixed(const float _float);
	Fixed(const Fixed &_Fixed);
	~Fixed(void);
	
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

	bool	operator>(const Fixed &_Fixed) const;
	bool	operator<(const Fixed &_Fixed) const;
	bool	operator>=(const Fixed &_Fixed) const;
	bool	operator<=(const Fixed &_Fixed) const;
	bool	operator==(const Fixed &_Fixed) const;
	bool	operator!=(const Fixed &_Fixed) const;
	Fixed	operator+(const Fixed &_Fixed) const;
	Fixed	operator-(const Fixed &_Fixed) const;
	Fixed	operator*(const Fixed &_Fixed) const;
	Fixed	operator/(const Fixed &_Fixed) const;
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	Fixed&	operator=(const Fixed &_Fixed);

	static Fixed&	min(Fixed &_Fixed1, Fixed &_Fixed2);
	static const Fixed&	min(const Fixed &_Fixed1, const Fixed &_Fixed2);
	static Fixed&	max(Fixed &_Fixed1, Fixed &_Fixed2);
	static const Fixed&	max(const Fixed &_Fixed1, const Fixed &_Fixed2);
private:
	int	Num;
	static const int	PosPoint = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& _Fixed);

#endif