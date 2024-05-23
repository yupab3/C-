#include "funcs.hpp"

Base * generate(void){
	int a = rand();
	switch(a % 3)
	{
		case 0:
			return new A;
			break;
		case 1:
			return new B;
			break;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B";
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C";
	}
}

void identify(Base& p){
	try
	{
		A& tmp = dynamic_cast<A&>(p);
		tmp.~A();
		std::cout << "A";
	}
	catch(std::bad_cast &e)
	{
		try
		{
			B& tmp = dynamic_cast<B&>(p);
			tmp.~B();
			std::cout << "B";
		}
		catch(std::bad_cast &e)
		{
			try
			{
				C& tmp = dynamic_cast<C&>(p);
				tmp.~C();
				std::cout << "C";
			}
			catch(std::bad_cast &e)
			{
				std::cout << "Casting Error!!\n";
			}
		}
	}
}