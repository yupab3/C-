#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	int				idx = 1;
	PmergeMe		tmp;
	struct timeval	v_start, v_end, d_start, d_end;

	if (argc == 1)
		return (1);
	try
	{
		while (idx < argc)
		{
			tmp.readNum(argv[idx]);
			idx++;
		}
		std::cout << "bf[vector]: ";
		tmp.printVectorData();
		std::cout << "bf[deque]: ";
		tmp.printDequeData();
		gettimeofday(&v_start, NULL);
		tmp.vectorFordJohnson();
		gettimeofday(&v_end, NULL);
		gettimeofday(&d_start, NULL);
		tmp.dequeFordJohnson();
		gettimeofday(&d_end, NULL);
		std::cout << "af[vector]: ";
		tmp.printVectorData();
		std::cout << "af[deque]: ";
		tmp.printDequeData();
		std::cout << "Time to process a range of " << tmp.getSize() << " elements with std::vector : " << (v_end.tv_sec - v_start.tv_sec) * 1000000 + v_end.tv_usec - v_start.tv_usec << " us\n";
		std::cout << "Time to process a range of " << tmp.getSize() << " elements with std::deque  : " << (d_end.tv_sec - d_start.tv_sec) * 1000000 + d_end.tv_usec - d_start.tv_usec << " us\n";
		std::cout << "Total compare count: " << tmp.getChain() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}