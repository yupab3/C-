#include "Weapon.hpp"

Weapon::Weapon(const std::string _type){
	std::cout << _type << " is created\n";
	type = _type;
}

Weapon::~Weapon(){
	std::cout << getType() << " is broken\n";
}

const std::string&	Weapon::getType(void) const{
	return (type);
}
void	Weapon::setType(const std::string _type){
	type = _type;
}