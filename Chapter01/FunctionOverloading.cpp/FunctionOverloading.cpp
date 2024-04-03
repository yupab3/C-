#include <iostream>

void	MyFunc(void)
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void	MyFunc(char c)
{
	std::cout << "MyFunc(char c) called, c = " << c << std::endl;
}

void	MyFunc(int a, int b)
{
	std::cout << "MyFunc(int a, int b) called, a = " << a << ", b = " << b << std::endl;
}

int	main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return (0);
}
