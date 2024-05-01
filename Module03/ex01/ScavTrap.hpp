#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap{
public:
	ScavTrap(const std::string &_Name);
	ScavTrap(const ScavTrap &_ScavTrap);
	ScavTrap&	operator=(const ScavTrap &_ScavTrap);
	~ScavTrap(void);

	void	attack(const std::string &target);
	void	guardGate(void);

private:
	ScavTrap(void);
};

#endif
