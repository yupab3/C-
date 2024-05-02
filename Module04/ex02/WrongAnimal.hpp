#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
protected:
	std::string	type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &_WrongAnimal);
	WrongAnimal& operator=(const WrongAnimal &_WrongAnimal);
	~WrongAnimal(void);

	void	makeSound(void) const;
};

#endif
