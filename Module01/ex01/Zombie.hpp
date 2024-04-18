#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
private:
	std::string name;
public:
	Zombie(void);
	Zombie(const std::string& name_tag);
	~Zombie();
	void	announce(void) const;
	void	set_name(std::string _name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif