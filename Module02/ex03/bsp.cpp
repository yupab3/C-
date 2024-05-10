# include "Point.hpp"

static Point	get_vector(Point const start, Point const end){
	Point	tmp(end.getFloatX() - start.getFloatX(), end.getFloatY() - start.getFloatY());
	return tmp;
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	float outer_a, outer_b, outer_c;
	Point	ab = get_vector(a, b);
	Point	bc = get_vector(b, c);
	Point	ca = get_vector(c, a);
	Point	ap = get_vector(a, point);
	Point	bp = get_vector(b, point);
	Point	cp = get_vector(c, point);
	outer_a = ab.getFloatX() * ap.getFloatY() - ab.getFloatY() * ap.getFloatX();
	outer_b = bc.getFloatX() * bp.getFloatY() - bc.getFloatY() * bp.getFloatX();
	outer_c = ca.getFloatX() * cp.getFloatY() - ca.getFloatY() * cp.getFloatX();
	if ((outer_a < 0 && outer_b < 0 && outer_c < 0) || (outer_a > 0 && outer_b > 0 && outer_c > 0)){
		return true;
	}
	return false;
}