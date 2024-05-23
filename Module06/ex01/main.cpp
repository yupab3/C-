#include "Serializer.hpp"

int	main(void)
{
	// Data*		ptr = new Data;
	// uintptr_t	ptradd = Serializer::serialize(ptr);
	Data		ptr;
	uintptr_t	ptradd = Serializer::serialize(&ptr);

	// ptr->x = 0;
	// ptr->y = 0;
	// std::cout << "ptr->x : " << &ptr->x << ", ptr->y : " << &ptr->y << '\n';
	// std::cout << "ptr : " << ptr << ", ptradd : " << ptradd << '\n';
	// std::cout << "ptr->x : " << ptr->x << ", ptr->y : " << ptr->y << '\n';
	// Serializer::deserialize(ptradd + 4)->x = 4;
	// std::cout << "ptr->x : " << ptr->x << ", ptr->y : " << ptr->y << '\n';
	// Serializer::deserialize(ptradd + 4)->y = 5;
	// std::cout << "ptr->x : " << ptr->x << ", ptr->y : " << ptr->y << '\n';
	// Serializer::deserialize(ptradd - 4)->y = 6;
	// std::cout << "ptr->x : " << ptr->x << ", ptr->y : " << ptr->y << '\n';
	// std::cout << "next area of ptr->y : " << Serializer::deserialize(ptradd + 4)->y << '\n';
	ptr.x = 0;
	ptr.y = 0;
	std::cout << "ptr.x : " << &ptr.x << ", ptr.y : " << &ptr.y << '\n';
	std::cout << "ptr : " << &ptr << ", ptradd : " << ptradd << '\n';
	std::cout << "ptr.x : " << ptr.x << ", ptr.y : " << ptr.y << '\n';
	Serializer::deserialize(ptradd + 4)->x = 4;
	std::cout << "ptr.x : " << ptr.x << ", ptr.y : " << ptr.y << '\n';
	Serializer::deserialize(ptradd + 4)->y = 5;
	std::cout << "ptr.x : " << ptr.x << ", ptr.y : " << ptr.y << '\n';
	Serializer::deserialize(ptradd - 4)->y = 6;
	std::cout << "ptr.x : " << ptr.x << ", ptr.y : " << ptr.y << '\n';
	std::cout << "next area of ptr.y : " << Serializer::deserialize(ptradd + 4)->y << '\n';
	return 0;
}