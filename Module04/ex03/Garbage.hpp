#ifndef GARBAGE_HPP
# define GARBAGE_HPP

#include "AMateria.hpp"

typedef struct garbageCollector
{
	AMateria	*garbage;
	struct garbageCollector	*next;
} gc;

class Garbage
{
private:
	gc			*gc_head;
public:
	Garbage(void);
	virtual ~Garbage(void);

	void	collectGarbage(AMateria* m);
private:
	Garbage(const Garbage &_Garbage);
	Garbage&	operator=(const Garbage &_Garbage);
};

#endif
