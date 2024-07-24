#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong argument\n";
		return 1;
	}
	try
	{
		RPN	rpn;
		rpn.solver(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}