#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	std::cout << "WrongAnimal 디폴트 생성자 호출~\n";
	type = "Void";
}

WrongAnimal::WrongAnimal(const WrongAnimal &_WrongAnimal){
	std::cout << "WrongAnimal 복사 생성자 호출~\n";
	type = _WrongAnimal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &_WrongAnimal){
	std::cout << "WrongAnimal 대입 연산자 호출~\n";
	if (this == &_WrongAnimal){
		return *this;
	}
	type = _WrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal 소멸자 호출~\n";
};

void	WrongAnimal::makeSound(void) const{
	std::cout << type << ": 잘못된 동물!\n";
}
