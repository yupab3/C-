#include "Ice.hpp"

Ice::Ice(void) :AMateria("ice"){
	std::cout << "Ice 생성자 호출~\n";
}

Ice::Ice(const Ice &_Ice) :AMateria(_Ice.type){
	std::cout << "Ice 복사 생성자 호출~\n";
}

Ice& Ice::operator=(const Ice &_Ice){
	if (this == &_Ice){
		return *this;
	}
	type = _Ice.type;
	return *this;
}

Ice::~Ice(void){
	std::cout << "Ice 소멸자 호출~\n";
}

AMateria*	Ice::clone() const{
	return new Ice();
}
void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
