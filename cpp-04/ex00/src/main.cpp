#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {

	std::cout << "Creating 3 animals\n" << std::endl;

	const Animal* meta = new Animal();
	std::cout << std::endl;

	const Animal* dog = new Dog();
	std::cout << std::endl;

	const Animal* cat = new Cat();
	std::cout << std::endl;


	std::cout << meta->getType() << " : ";
	meta->makeSound();

	std::cout << dog->getType() << " : ";
	dog->makeSound();

	std::cout << cat->getType() << " : ";
	cat->makeSound();


	std::cout << "\nDestroying 3 animals\n" << std::endl;
	delete meta;
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;

	delete cat;


	std::cout << "\nCreating 2 wrong animals\n" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;


	std::cout << wrongAnimal->getType() << " : ";
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << " : ";
	wrongCat->makeSound();


	std::cout << "\nDestroying 2 wrong animals\n" << std::endl;

	delete wrongAnimal;
	std::cout << std::endl;

	delete wrongCat;

	return (0);
}
