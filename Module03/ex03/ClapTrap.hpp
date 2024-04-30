#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap{
public:
	ClapTrap(const std::string &_Name);
	ClapTrap(const ClapTrap &_ClapTrap);
	ClapTrap&	operator=(const ClapTrap &_ClapTrap);
	~ClapTrap(void);

	virtual void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
protected:
	std::string	Name;
	int			HitPoint;
	int			EnergyPoint;
	int			AttackDamage;
private:
	ClapTrap(void);
};

#endif
