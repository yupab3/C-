#include "ClapTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	std::cout << '\n';
	C.attack("jaejilee");
	std::cout << '\n';
	C.takeDamage(1);
	C.beRepaired(1);
	std::cout << '\n';
	return 0;
}