#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	ClapTrap C("Sungyoon");
	ScavTrap S("Jaejilee");
	FragTrap F("Yeoshin");
	std::cout << '\n';
	C.attack("jaejilee");
	S.attack("yeoshin");
	F.attack("dongyeuk");
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
	return 0;
}