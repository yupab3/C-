#include "HumanA.hpp"

HumanA::HumanA(const std::string _name, Weapon &_club) :club(_club) {
	std::cout << "HumanA - " << _name << " is created\n";
	name = _name;
}

HumanA::~HumanA(){
	std::cout << "HumanA - " << name << " is deleted\n";
}

void	HumanA::attack() const{
	std::cout << name << " attacks with their " << club.getType() << '\n';
}