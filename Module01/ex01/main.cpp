#include "Zombie.hpp"

int	main(void){
	Zombie	*ztr = zombieHorde(30, "sungyoon");
	for (int i = 0; i < 30; i++){
		if (i % 2 == 1) ztr[i].announce();
	}
	for (int i = 0; i < 30; i++){
		if (i % 2 == 0) ztr[i].announce();
	}
	if (ztr != NULL) delete[] ztr;
	return 0;
}
