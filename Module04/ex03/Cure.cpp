#include "Cure.hpp"

Cure::Cure(void) :AMateria("cure"){
	std::cout << "Cure 생성자 호출~\n";
}

Cure::Cure(const Cure &_Cure) :AMateria(_Cure.type){
	std::cout << "Cure 복사 생성자 호출~\n";
}

Cure& Cure::operator=(const Cure &_Cure){
	if (this == &_Cure){
		return *this;
	}
	type = _Cure.type;
	return *this;
}

Cure::~Cure(void){
	std::cout << "Cure 소멸자 호출~\n";
}

AMateria*	Cure::clone() const{
	return new Cure();
}
void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
