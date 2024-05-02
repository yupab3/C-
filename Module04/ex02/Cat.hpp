#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
private:
	Brain	*small_universe;
public:
	Cat(void);
	Cat(const Cat &_Cat);
	Cat& operator=(const Cat &_Cat);
	~Cat(void);

	virtual void	makeSound(void) const;
};

#endif
