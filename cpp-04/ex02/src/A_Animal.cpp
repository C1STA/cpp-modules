#include <iostream>
#include "A_Animal.hpp"

A_Animal::A_Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructed" << std::endl;
}

A_Animal&	A_Animal::operator=(const A_Animal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

A_Animal::~A_Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

A_Animal::A_Animal(const std::string& type) : _type(type)
{
	std::cout << "Animal constructed" << std::endl;
}

std::string	A_Animal::getType() const
{
	return (_type);
}
