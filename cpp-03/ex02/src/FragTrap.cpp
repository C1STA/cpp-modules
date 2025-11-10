#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructed from " << other._name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called from " << other._name << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (!_hitPoints)
			std::cout << "FragTrap " << _name << " can't attack. Already defeated!" << std::endl;
		else if (!_energyPoints)
			std::cout << "FragTrap " << _name << " can't attack. No more energy points!" << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	if (_hitPoints)
		std::cout << "FragTrap " << _name << " agreed for a high five!" << std::endl;
	else
		std::cout << "FiveTrap " << _name << " can't agree for a high five. Already defeated!" << std::endl;
}
