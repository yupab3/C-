#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap{
private:
	std::string	Name;
	int			HitPoint;
	int			EnergyPoint;
	int			AttackDamage;

public:
	ClapTrap(const std::string &_Name);
	ClapTrap(const ClapTrap &_ClapTrap);
	ClapTrap&	operator=(const ClapTrap &_ClapTrap);
	~ClapTrap(void);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	const int&	getAttackDamage(void) const;

private:
	ClapTrap(void);
};

#endif
