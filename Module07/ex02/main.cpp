#include <iostream>
#include "Array.hpp" // case 2
// #include <Array> // case 1

// class	Point // case 4
// {
// public:
// 	int x;
// 	int y;
// };

// void	asd(void) // case 5
// {
// 	system("leaks main");
// }

int	main()
{
// case 1
	// std::array<int, 30>		intArrayPtrArray;
	// const std::array<int, 30>	constArrayint;

// case 2
	Array<Array<int>*>		intArrayPtrArray(30);
	Array<int>		nullArray(0);
	Array<int>		intArray1(30);
	Array<int>		intArray2(30);
	Array<unsigned int>	unsignedintArray(30);
	intArray1[1] = 1;
	intArray2[1] = 2;
	unsignedintArray[1] = 2147483648;
	intArrayPtrArray[0] = &intArray1;

	std::cout << "intArray1[1] = " << intArray1[1] << '\n';
	std::cout << "intArray2[1] = " << intArray2[1] << '\n';
	std::cout << "unsignedintArray[1] = " << unsignedintArray[1] << '\n';
	intArray1 = intArray2;
	std::cout << "intArray1[1] = " << intArray1[1] << '\n';
	std::cout << "intArrayPtrArray[0] = " << (*intArrayPtrArray[0])[1] << " " << intArrayPtrArray[0]->operator[](1) << '\n';

// case 3
	// Array<const int>	arrConstint(10);
	// arrConstint[1] = 1;
	// const Array<int>	constArrayint(10);
	// constArrayint[1] = 1;

// case 4
	// Array<Point>	PointArray(30);
	// PointArray[0].x = 1;
	// PointArray[0].y = 2;
	// std::cout << "PointArray[0].x = " << PointArray[0].x << ", PointArray[0].y = " << PointArray[0].y << '\n';

// case 5
	// atexit(asd);

}