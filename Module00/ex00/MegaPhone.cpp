#include <iostream>

int	main(int argc, char **argv)
{
	std::string str;
	size_t		idx;
	int			count;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	count = 1;
	while (count < argc)
	{
		idx = 0;
		str = argv[count];
		while (idx < str.size())
		{
			str[idx] = std::toupper(str[idx]);
			idx++;
		}
		std::cout << str;
		count++;
	}
	std::cout << '\n';
}