#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap{
public:
	FragTrap(const std::string &_Name);
	FragTrap(const FragTrap &_FragTrap);
	FragTrap&	operator=(const FragTrap &FragTrap);
	~FragTrap(void);

	void	highFivesGuys(void);

private:
	FragTrap(void);
};

#endif
