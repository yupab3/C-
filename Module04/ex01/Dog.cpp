#include "Dog.hpp"

Dog::Dog(void) :Animal(){
	std::cout << "Dog 디폴트 생성자 호출~\n";
	small_universe = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog &_Dog) :Animal(){
	std::cout << "Dog 복사 생성자 호출~\n";
	small_universe = new Brain(*_Dog.small_universe);
	type = _Dog.type;
}

Dog& Dog::operator=(const Dog &_Dog){
	std::cout << "Dog 대입 연산자 호출~\n";
	if (this == &_Dog){
		return *this;
	}
	*small_universe = *_Dog.small_universe;
	type = _Dog.type;
	return *this;
}

void* Dog::getAdd(void) const{
	return (small_universe);
}

Dog::~Dog(void){
	std::cout << "Dog 소멸자 호출~\n";
	delete small_universe;
};

void	Dog::makeSound(void) const{
	std::cout << type << ": 멍!\n";
}
