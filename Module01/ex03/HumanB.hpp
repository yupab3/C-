#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
public:
	HumanB(const std::string _name);
	~HumanB();
	void	attack() const;
	void	setWeapon(Weapon &_club);
private:
	std::string name;
	Weapon		*club;
	HumanB(void);
};

#endif
