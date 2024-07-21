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
		bc.parseMarket("data.csv");
		bc.printAmount(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}