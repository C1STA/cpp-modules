#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong Animal")
{
	std::cout << "Default Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "Wrong Animal copy constructed" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	std::cout << "Wrong Animal constructed" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong, Wrong..." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}
