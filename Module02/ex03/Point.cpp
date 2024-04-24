#include "Point.hpp"

Point::Point(void):x(0), y(0){}

Point::Point(const float _x, const float _y):x(_x), y(_y){}

Point::Point(const Point& _Point):x(_Point.x), y(_Point.y){}

Point::~Point(void){};

void	Point::printData(void) const{
	std::cout << "x: " << x.toFloat() << ", y: " << y.toFloat() << '\n';
}
Point&	Point::operator=(const Point &_Point){
	if (this == &_Point) return *this;
	else return *this;
}

float	Point::getFloatX(void) const{
	return x.toFloat();
}

float	Point::getFloatY(void) const{
	return y.toFloat();
}