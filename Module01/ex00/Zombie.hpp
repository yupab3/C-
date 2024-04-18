#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:

	std::string name;

	public:

	Zombie(const std::string& name_tag);
	~Zombie();
	void	announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif