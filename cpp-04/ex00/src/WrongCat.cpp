#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") 
{
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "Wrong Cat copy constructed" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Wrong Cat copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow..." << std::endl;
}
