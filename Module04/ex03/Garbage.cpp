#include "Garbage.hpp"

Garbage::Garbage(void){
	std::cout << "가비지 컬렉터 생성자 호출~\n";
	gc_head = NULL;
}

Garbage::~Garbage(void){
	gc	*tmp = gc_head;
	while (tmp != NULL){
		gc_head = gc_head->next;
		delete tmp->garbage;
		delete tmp;
		tmp = gc_head;
	}
}

void	Garbage::collectGarbage(AMateria* m){
	gc	*tmp = new gc;
	tmp->garbage = m;
	tmp->next = gc_head;
	gc_head = tmp;
}
