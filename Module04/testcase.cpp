#include <iostream>

int	main(void){
	int	rm = 10;
	int const&	icr_rm = 20;
	const int&	cir_rm = 30;

	std::cout << icr_rm << '\n';
	std::cout << cir_rm << '\n';

	rm = 20;

	std::cout << icr_rm << '\n';
	std::cout << cir_rm << '\n';

	return 0;
}