#include <iostream>
#include "Dog.hpp"

Dog::Dog() : A_Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : A_Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructed" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		(*this->_brain) = (*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof, Woof!" << std::endl;
}

std::string	Dog::getIdea(int n) const
{ 
	return (this->_brain->getIdea(n));
}

void	Dog::setIdea(std::string idea, int n)
{
	this->_brain->setIdea(idea, n);
}
