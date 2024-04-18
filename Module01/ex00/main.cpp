#include "Zombie.hpp"

int	main(void){
	Zombie*	corpse = newZombie("Sungyoon");

	randomChump("Nobody");

	corpse->announce();

	delete corpse;

	std::cout << "exit program!!!!\n";
	return 0;
}
