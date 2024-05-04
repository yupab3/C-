#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource 생성자 호출~\n";
	for (int i = 0; i < 4; i++){
		slot[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &_MateriaSource){
	std::cout << "MateriaSource 복사 생성자 호출~\n";
	for (int i = 0; i < 4; i++){
		if (_MateriaSource.slot[i] != NULL){
			slot[i] = _MateriaSource.slot[i]->clone();
			collectGarbage(slot[i]);
		}
		else{
			slot[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &_MateriaSource){
	if (this == &_MateriaSource){
		return *this;
	}
	for (int i = 0; i < 4; i++){
		if (_MateriaSource.slot[i] != NULL){
			slot[i] = _MateriaSource.slot[i]->clone();
			collectGarbage(slot[i]);
		}
		else{
			slot[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource 소멸자 호출~\n";
}

void MateriaSource::learnMateria(AMateria* m){
	int i;
	for (i = 0; i < 4; i++){
		if (slot[i] == NULL){
			break;
		}
	}
	if (i < 4){
		slot[i] = m->clone();
	}
	collectGarbage(slot[i]);
}

AMateria* MateriaSource::createMateria(std::string const & type){
	int i;
	for (i = 0; i < 4; i++){
		if (slot[i]->getType() == type){
			break;
		}
	}
	if (i < 4){
		return slot[i]->clone();
	}
	return 0;
}
