#include "ClapTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	std::cout << '\n';
	C.attack("sungyoon");
	C.takeDamage(C.getAttackDamage());
	std::cout << '\n';
	C.beRepaired(1);
	std::cout << '\n';
	return 0;
}
