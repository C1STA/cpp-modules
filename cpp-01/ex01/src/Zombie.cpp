#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Creating zombie at adress: " << this << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying zombie at adress: " << this << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
