#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
public:
	HumanA(const std::string _name, Weapon &_club);
	~HumanA();
	void	attack() const;
private:
	std::string name;
	Weapon		&club;
	HumanA(void);
};

#endif