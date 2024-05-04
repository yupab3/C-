#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Garbage.hpp"

class MateriaSource : public IMateriaSource, public Garbage
{
private:
	AMateria	*slot[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &_MateriaSource);
	MateriaSource&	operator=(const MateriaSource &_MateriaSource);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
