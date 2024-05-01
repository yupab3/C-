#include "ScavTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	ScavTrap S("Jaejilee");
	std::cout << '\n';
	C.attack("jaejilee");
	S.takeDamage(C.getAttackDamage());
	std::cout << '\n';
	S.attack("Sungyoon");
	C.takeDamage(S.getAttackDamage());
	std::cout << '\n';
	C.beRepaired(1);
	std::cout << '\n';
	S.beRepaired(3);
	std::cout << '\n';
	return 0;
}
