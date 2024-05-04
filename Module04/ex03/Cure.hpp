#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &_Cure);
	Cure& operator=(const Cure &_Cure);
	virtual ~Cure(void);

	virtual AMateria*	clone() const;
	virtual void	use(ICharacter& target);
};

#endif
