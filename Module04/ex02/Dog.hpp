#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
private:
	Brain	*small_universe;
public:
	Dog(void);
	Dog(const Dog &_Dog);
	Dog& operator=(const Dog &_Dog);
	~Dog(void);

	void* getAdd(void) const;
	virtual void	makeSound(void) const;
};

#endif
