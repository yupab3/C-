#include "WrongCat.hpp"

WrongCat::WrongCat(void) :WrongAnimal(){
	std::cout << "WrongCat 디폴트 생성자 호출~\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &_WrongCat) :WrongAnimal(){
	std::cout << "WrongCat 복사 생성자 호출~\n";
	type = _WrongCat.type;
}

WrongCat& WrongCat::operator=(const WrongCat &_WrongCat){
	std::cout << "WrongCat 대입 연산자 호출~\n";
	if (this == &_WrongCat){
		return *this;
	}
	type = _WrongCat.type;
	return *this;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat 소멸자 호출~\n";
};

void	WrongCat::makeSound(void) const{
	std::cout << type << ": 잘못됐다냥~\n";
}
