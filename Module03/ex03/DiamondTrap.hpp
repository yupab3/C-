#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
public:
	DiamondTrap(const std::string &_Name);
	DiamondTrap(const DiamondTrap &_DiamondTrap);
	DiamondTrap&	operator=(const DiamondTrap &_DiamondTrap);
	~DiamondTrap(void);
	void	whoAmI(void) const;

private:
	std::string	Name;
	DiamondTrap(void);
};

#endif
