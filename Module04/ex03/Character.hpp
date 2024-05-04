#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Garbage.hpp"

class Character : public ICharacter, public Garbage
{
private:
	std::string	name;
	AMateria	*slot[4];
public:
	Character(void);
	Character(const Character &_Character);
	Character(const std::string &_name);
	Character&	operator=(const Character &_Character);
	virtual ~Character(void);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
