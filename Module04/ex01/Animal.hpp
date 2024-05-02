#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(const Animal &_Animal);
	Animal& operator=(const Animal &_Animal);
	virtual ~Animal(void);

	virtual void	makeSound(void) const;
};

#endif
