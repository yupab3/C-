#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &_Ice);
	Ice& operator=(const Ice &_Ice);
	virtual ~Ice(void);

	virtual AMateria*	clone() const;
	virtual void	use(ICharacter& target);
};

#endif
