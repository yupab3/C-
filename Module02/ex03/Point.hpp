#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point{
public:
	Point(void);
	Point(const float _x, const float _y);
	Point(const Point& _Point);
	~Point(void);

	void	printData(void) const;
	Point&	operator=(const Point &_Point);
	float	getFloatX(void) const;
	float	getFloatY(void) const;
private:
	const Fixed x;
	const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
