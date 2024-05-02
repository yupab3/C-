#include "Animal.hpp"

Animal::Animal(void){
	std::cout << "Animal 디폴트 생성자 호출~\n";
	type = "Void";
}

Animal::Animal(const Animal &_Animal){
	std::cout << "Animal 복사 생성자 호출~\n";
	type = _Animal.type;
}

Animal& Animal::operator=(const Animal &_Animal){
	std::cout << "Animal 대입 연산자 호출~\n";
	if (this == &_Animal){
		return *this;
	}
	type = _Animal.type;
	return *this;
}

Animal::~Animal(void){
	std::cout << "Animal 소멸자 호출~\n";
};
