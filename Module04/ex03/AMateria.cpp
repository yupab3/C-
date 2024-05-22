#include "AMateria.hpp"

AMateria::AMateria(void) :type("empty"){
	std::cout << "AMateria 생성자 호출~\n";
};
AMateria::AMateria(const AMateria &_AMateria) :type(_AMateria.getType()){
	std::cout << "AMateria 복사 생성자 호출~\n";
}
AMateria::AMateria(std::string const & type) :type(type){
	std::cout << "AMateria 생성자 호출~\n";
}

AMateria::~AMateria(void){
	std::cout << "AMateria 소멸자 호출~\n";
}

AMateria&	AMateria::operator=(const AMateria &_AMateria){
	if (this == &_AMateria){
		return *this;
	}
	return *this;
}

std::string const & AMateria::getType() const{
	return type;
}

void		AMateria::use(ICharacter& target){
	std::cout << target.getName() << "어케 호출했음?";
}
