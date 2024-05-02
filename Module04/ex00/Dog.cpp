#include "Dog.hpp"

Dog::Dog(void) :Animal(){
	std::cout << "Dog 디폴트 생성자 호출~\n";
	type = "Dog";
}

Dog::Dog(const Dog &_Dog) :Animal(){
	std::cout << "Dog 복사 생성자 호출~\n";
	type = _Dog.type;
}

Dog& Dog::operator=(const Dog &_Dog){
	std::cout << "Dog 대입 연산자 호출~\n";
	if (this == &_Dog){
		return *this;
	}
	type = _Dog.type;
	return *this;
}

Dog::~Dog(void){
	std::cout << "Dog 소멸자 호출~\n";
};

void	Dog::makeSound(void) const{
	std::cout << type << ": 멍!\n";
}
