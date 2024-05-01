#include "DiamondTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	ScavTrap S("Jaejilee");
	FragTrap F("Yeoshin");
	DiamondTrap D("Younghoc");
	std::cout << '\n';
	C.attack("jaejilee");
	S.takeDamage(C.getAttackDamage());
	std::cout << '\n';
	S.attack("yeoshin");
	F.takeDamage(S.getAttackDamage());
	std::cout << '\n';
	F.attack("Younghoc");
	D.takeDamage(F.getAttackDamage());
	std::cout << '\n';
	D.attack("sungyoon");
	C.takeDamage(D.getAttackDamage());
	std::cout << '\n';
	C.beRepaired(1);
	std::cout << '\n';
	S.guardGate();
	S.beRepaired(3);
	std::cout << '\n';
	F.highFivesGuys();
	F.beRepaired(5);
	std::cout << '\n';
	D.beRepaired(7);
	D.guardGate();
	D.highFivesGuys();
	D.whoAmI();
	std::cout << '\n';
	return 0;
}
