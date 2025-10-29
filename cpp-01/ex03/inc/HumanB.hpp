#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;
public:
	HumanB(const std::string& name);
	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif