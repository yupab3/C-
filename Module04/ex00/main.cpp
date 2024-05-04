#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void){
	Animal *a1 = new Animal();
	std::cout << '\n';
	Animal *d1 = new Dog();
	std::cout << '\n';
	Animal *c1 = new Cat();
	std::cout << '\n';

	a1->makeSound();
	std::cout << '\n';
	d1->makeSound();
	std::cout << '\n';
	c1->makeSound();
	std::cout << '\n';

	delete c1;
	std::cout << '\n';
	delete d1;
	std::cout << '\n';
	delete a1;
	std::cout << '\n';

	WrongAnimal *wa = new WrongAnimal();
	std::cout << '\n';
	WrongAnimal *wc = new WrongCat();
	std::cout << '\n';

	wa->makeSound();
	std::cout << '\n';
	wc->makeSound();
	std::cout << '\n';

	delete wa;
	std::cout << '\n';
	delete wc;
	std::cout << '\n';

	// WrongCat *wc1 = new WrongAnimal();
	WrongCat *wc2 = new WrongCat();
	std::cout << '\n';

	wc2->makeSound();
	std::cout << '\n';

	delete wc2;
	// while (1);
	return 0;
}