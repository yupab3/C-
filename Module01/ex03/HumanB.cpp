
#include "HumanB.hpp"

HumanB::HumanB(const std::string _name){
	std::cout << "HumanB - " << _name << " is created\n";
	name = _name;
	club = NULL;
}

HumanB::~HumanB(){
	std::cout << "HumanB - " << name << " is deleted\n";
}

void	HumanB::attack() const{
	if (club != NULL){
		std::cout << name << " attacks with their " << club->getType() << '\n';
	} else{
		std::cout << name << " attacks with their fucxing empty weapon" << '\n';
	}
}

void	HumanB::setWeapon(Weapon &_club){
	club = &_club;
}
