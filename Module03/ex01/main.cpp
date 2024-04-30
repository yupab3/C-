#include "ScavTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	ScavTrap S("Jaejilee");
	std::cout << '\n';
	C.attack("jaejilee");
	S.attack("dongyeuk");
	std::cout << '\n';
	C.takeDamage(1);
	C.beRepaired(1);
	std::cout << '\n';
	S.takeDamage(3);
	S.beRepaired(3);
	std::cout << '\n';
	return 0;
}