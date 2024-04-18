#include "Zombie.hpp"

void	Zombie::announce(void) const{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(const std::string& name_tag){
	name = name_tag;
	std::cout << "Corpse got " << name_tag << "'s soul...\n";
}

Zombie::Zombie(void){
	std::cout << "Corpse got " << "Nobody" << "'s soul...\n";
}

Zombie::~Zombie(){
	std::cout << name << "'s soul is free...\n";
}

void	Zombie::set_name(std::string _name){
	name = _name;
	std::cout << "Corpse got " << _name << "'s soul...\n";
}