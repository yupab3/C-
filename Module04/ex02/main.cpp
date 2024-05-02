#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void){
	// Animal *a1 = new Animal();
	// std::cout << '\n';
	Animal *d1 = new Dog();
	std::cout << '\n';
	Animal *c1 = new Cat();
	std::cout << '\n';

	// a1->makeSound();
	// std::cout << '\n';
	d1->makeSound();
	std::cout << '\n';
	c1->makeSound();
	std::cout << '\n';

	Dog	d2;
	Dog d3(d2);

	std::cout << d2.getAdd() << '\n';
	std::cout << d3.getAdd() << '\n';

	d3 = d2;

	std::cout << d2.getAdd() << '\n';
	std::cout << d3.getAdd() << '\n';
	
	delete c1;
	std::cout << '\n';
	delete d1;
	std::cout << '\n';
	// delete a1;
	// std::cout << '\n';

	// while (1);
	return 0;
}