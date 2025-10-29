#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Creating zombie " << this->name << "..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroying zombie " << this->name << "..." << std::endl;
}
