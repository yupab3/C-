#include "Point.hpp"

int main( void ) {
const Point a(3, 0);
const Point b(0, 5);
const Point c(-3, 0);
const Point point1(0, 4);
const Point point2(2, 0);
const Point point3(2, 1);

a.printData();
b.printData();
c.printData();
point1.printData();

std::cout << bsp(a, b, c, point1) << '\n';
std::cout << bsp(a, b, c, point2) << '\n';
std::cout << bsp(a, b, c, point3) << '\n';
return 0;
}