#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructed" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		(*this->_brain) = (*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow, Meow! " << std::endl;
}

std::string	Cat::getIdea(int n)  const
{ 
	return (this->_brain->getIdea(n));
}

void	Cat::setIdea(std::string idea, int n)
{
	this->_brain->setIdea(idea, n);
}
