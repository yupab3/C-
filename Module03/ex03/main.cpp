#include "DiamondTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	ScavTrap S("Jaejilee");
	FragTrap F("Yeoshin");
	DiamondTrap D("Younghoc");
	std::cout << '\n';
	C.attack("jaejilee");
	S.attack("yeoshin");
	F.attack("Younghoc");
	D.attack("dongyeuk");
	std::cout << '\n';
	C.takeDamage(1);
	C.beRepaired(1);
	std::cout << '\n';
	S.guardGate();
	S.takeDamage(3);
	S.beRepaired(3);
	std::cout << '\n';
	F.highFivesGuys();
	F.takeDamage(5);
	F.beRepaired(5);
	std::cout << '\n';
	D.takeDamage(7);
	D.beRepaired(7);
	D.guardGate();
	D.highFivesGuys();
	D.whoAmI();
	std::cout << '\n';
	return 0;
}