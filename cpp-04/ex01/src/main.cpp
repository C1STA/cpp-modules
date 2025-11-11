#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "Creating 4 animals, 2 dogs and 2 cats\n" << std::endl;

	Animal	*animal[4];

	for (int i = 0; i < 4; i++)
	{
		std::cout << "animal[" << i << "]: "<< std::endl;
		if (i % 2)
			animal[i] = new Cat;
		else
			animal[i] = new Dog;
		std::cout << std::endl;
	}


	std::cout << "\nCreating a cat\n" << std::endl;
	
	Cat	*cat = new Cat();
	

	std::cout << "\nSetting ideas ...\n" << std::endl;

	cat->setIdea("index_4", 4);
	cat->setIdea("index_42", 42);
	cat->setIdea("", 4);
	cat->setIdea("A test..", 142);


	std::cout << "\nGetting ideas ...\n" << std::endl;
	
	std::cout << cat->getIdea(4) << std::endl;
	std::cout << cat->getIdea(42) << std::endl;
	std::cout << cat->getIdea(11) << std::endl;
	std::cout << cat->getIdea(-3) << std::endl;


	std::cout << "\nTesting copies ...\n" << std::endl;
	
	Cat	copycat(*cat);
	std::cout << std::endl;

	std::cout << copycat.getIdea(4) << std::endl;

	copycat.setIdea("I am a copy!", 4);
	std::cout << copycat.getIdea(4) << std::endl;

	std::cout << cat->getIdea(4) << std::endl << std::endl;

	delete cat;
	std::cout << std::endl;

	Cat cat_operator;
	std::cout << std::endl;

	cat_operator = copycat;

	std::cout << cat_operator.getIdea(4) << std::endl;

	cat_operator.setIdea("I am a copy assignment!", 4);
	std::cout << cat_operator.getIdea(4) << std::endl;

	std::cout << copycat.getIdea(4) << std::endl;


	std::cout << "\nDestroying 4 animals, 2 dogs and 2 cats\n" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "animal[" << i << "]:" << std::endl;
		delete animal[i];
		std::cout << std::endl;
	}
	std::cout << "-- copycat & cat_operator remaining ...\n" << std::endl;
	return (0);
}
