#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	int			idx = 1;
	PmergeMe	tmp;

	std::cout << argc;
	try
	{
		while (idx < argc)
		{
			tmp.readNum(argv[idx]);
			idx++;
		}
		tmp.vectorFordJohnson();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}