#include "funcs.hpp"

int main(void)
{
	srand(time(NULL));
	Base*	ptr1 = generate();
	Base*	ptr2 = generate();
	Base*	ptr3 = generate();
	Base*	ptr4 = generate();
	Base*	ptr5 = generate();
	Base&	ref1 = *ptr1;
	Base&	ref2 = *ptr2;
	Base&	ref3 = *ptr3;
	Base&	ref4 = *ptr4;
	Base&	ref5 = *ptr5;
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	identify(ptr4);
	identify(ptr5);
	std::cout << '\n';
	identify(ref1);
	identify(ref2);
	identify(ref3);
	identify(ref4);
	identify(ref5);
	std::cout << '\n';
}