#include "Zombie.hpp"

void	Zombie::announce(void) const{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(const std::string& name_tag){
	name = name_tag;
	std::cout << "Corpse got " << name_tag << "'s soul...\n";
}

Zombie::~Zombie(){
	std::cout << name << "'s soul is free...\n";
}
