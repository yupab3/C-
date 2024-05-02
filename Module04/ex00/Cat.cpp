#include "Cat.hpp"

Cat::Cat(void) :Animal(){
	std::cout << "Cat 디폴트 생성자 호출~\n";
	type = "Cat";
}

Cat::Cat(const Cat &_Cat) :Animal(){
	std::cout << "Cat 복사 생성자 호출~\n";
	type = _Cat.type;
}

Cat& Cat::operator=(const Cat &_Cat){
	std::cout << "Cat 대입 연산자 호출~\n";
	if (this == &_Cat){
		return *this;
	}
	type = _Cat.type;
	return *this;
}

Cat::~Cat(void){
	std::cout << "Cat 소멸자 호출~\n";
};

void	Cat::makeSound(void) const{
	std::cout << type << ": 냥~\n";
}
