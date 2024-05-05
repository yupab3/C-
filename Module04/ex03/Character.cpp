#include "Character.hpp"

Character::Character(void) :name("anonymous"){
	std::cout << "Character 생성자 호출~\n";
	for (int i = 0; i < 4; i++){
		slot[i] = NULL;
	}
}

Character::Character(const std::string &_name) :name(_name){
	std::cout << "Character 생성자 호출~\n";
	for (int i = 0; i < 4; i++){
		slot[i] = NULL;
	}
}

Character::Character(const Character &_Character){
	std::cout << "Character 복사 생성자 호출~\n";
	for (int i = 0; i < 4; i++){
		if (_Character.slot[i] != NULL){
			slot[i] = _Character.slot[i]->clone();
			collectGarbage(slot[i]);
		}
		else{
			slot[i] = NULL;
		}
	}
}

Character&	Character::operator=(const Character &_Character){
	if (this == &_Character){
		return *this;
	}
	for (int i = 0; i < 4; i++){
		if (_Character.slot[i] != NULL){
			slot[i] = _Character.slot[i]->clone();
			collectGarbage(slot[i]);
		}
		else{
			slot[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(void){
	std::cout << "Character 소멸자 호출~\n";
}

std::string const & Character::getName() const{
	return name;
}

void Character::equip(AMateria* m){
	if (m == NULL){
		return;
	}
	int i;
	for (i = 0; i < 4; i++){
		if (slot[i] == NULL){
			break;
		}
	}
	if (i < 4){
		slot[i] = m->clone();
		collectGarbage(slot[i]);
	}
}

void Character::unequip(int idx){
	if (0 <= idx && idx <= 3){
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){
	if (0 <= idx && idx <= 3){
		if (slot[idx] != NULL){
			slot[idx]->use(target);
		}
	}
}
