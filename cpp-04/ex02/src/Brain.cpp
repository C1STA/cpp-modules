#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructed" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

std::string	Brain::getIdea(int n) const
{
	if (n < 0 || n >= 100)
		return ("index overflow");
	return (_ideas[n]);
}

void	Brain::setIdea(std::string idea, int n)
{
	if (n < 0 || n >= 100)
	{
		std::cerr << "idea[" << n << "]: idea can't be set, out of range" << std::endl;
		return ;
	}
	if (!idea.size())
	{
		std::cerr << "idea[" << n << "]: idea can't be empty" << std::endl;
		return ;
	}
	this->_ideas[n] = idea;
}
