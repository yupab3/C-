#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde(int N, std::string _name){
	if (N < 1) return NULL;
	Zombie	*ztr = new Zombie[N];

	for (int i = 0; i < N; i++){
		std::stringstream ss;
		ss << i;
		std::string tmp = _name + ss.str();
		ztr[i].set_name(tmp);
	}
	return ztr;
}