#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong argument\n";
		return 1;
	}
	try
	{
		BitcoinExchange	bc;
		std::cout << "-----data-----\n";
		bc.parseMarket("data.csv");
		std::cout << "----market----\n";
		bc.printAmount(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}