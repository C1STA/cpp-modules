#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructed from " << other._name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called from " << other._name << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (!_hitPoints)
			std::cout << "ClapTrap " << _name << " can't attack. Already defeated!" << std::endl;
		else if (!_energyPoints)
			std::cout << "ClapTrap " << _name << " can't attack. No more energy points!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (amount >= _hitPoints)
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! ClapTrap " << _name << " has been defeated!" << std::endl;
		}
		else
		{
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! " << _hitPoints << " hit points left." << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << _name << " is already defeated!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points! " << _hitPoints << " hit points left." << std::endl;
	}
	else
	{
		if (!_hitPoints)
			std::cout << "ClapTrap " << _name << " can't be repaired. Already defeated!" << std::endl;
		else if (!_energyPoints)
			std::cout << "ClapTrap " << _name << " can't be repaired. No more energy points!" << std::endl;
	}
}
