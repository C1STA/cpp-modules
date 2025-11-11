#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructed" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "Animal constructed" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "An Animal makes a sound." << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}
