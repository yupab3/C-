#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain 디폴트 생성자 호출~\n";
	for (int i = 0; i < 100; i++){
		ideas[i] = "no idea";
	}
}

Brain::Brain(const Brain &_Brain){
	std::cout << "Brain 복사 생성자 호출~\n";
	for (int i = 0; i < 100; i++){
		ideas[i] = _Brain.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain &_Brain){
	std::cout << "Brain 대입 연산자 호출~\n";
	if (this == &_Brain){
		return *this;
	}
	for (int i = 0; i < 100; i++){
		ideas[i] = _Brain.ideas[i];
	}
	return *this;
}

Brain::~Brain(void){
	std::cout << "Brain 소멸자 호출~\n";
}
