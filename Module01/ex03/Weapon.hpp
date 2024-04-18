#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
public:
	Weapon(const std::string _type);
	~Weapon();
	const std::string&	getType(void) const;
	void	setType(const std::string _type);
private:
	std::string type;
	Weapon(void);
};

#endif