#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void	HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks without any weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
