#include <iostream>
#include "Array.hpp"

void	asd(void)
{
	system("leaks main");
}

class	Point
{
public:
	int x;
	int y;
};

int	main()
{
	Array<Array<int>*>		intArrayPtrArray(30);
	Array<int>		nullArray(0);
	Array<int>		intArray1(30);
	Array<int>		intArray2(30);
	Array<unsigned int>	unsignedintArray(30);
	Array<Point>	PointArray(30);

	intArray1[1] = 1;
	intArray2[1] = 2;
	unsignedintArray[1] = 2147483648;
	PointArray[0].x = 1;
	PointArray[0].y = 2;
	intArray1 = intArray2;
	intArrayPtrArray[0] = &intArray1;
	std::cout << PointArray[0].x << " " << PointArray[0].y << '\n';
	std::cout << (*intArrayPtrArray[0])[1] << '\n' << unsignedintArray[1];
	atexit(asd);
}