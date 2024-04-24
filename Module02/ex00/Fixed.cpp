#include "Fixed.hpp"

Fixed::Fixed(void) :Num(0){
	std::cout << "Default constructor called - " << Num << " \n";
}

Fixed::Fixed(Fixed& _Fixed) :Num(_Fixed.Num){
	std::cout << "Copy constructor called - " << Num << " \n";
}

Fixed& Fixed::operator=(const Fixed &_Fixed){
	std::cout << "Copy assignment operator called - " << _Fixed.Num << " \n";
	if (this == &_Fixed) return *this;
	Num = _Fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called - " << Num << "\n";
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called - " << Num << "\n";
	return (Num);
}

void	Fixed::setRawBits(int const raw){
	Num = raw;
}
