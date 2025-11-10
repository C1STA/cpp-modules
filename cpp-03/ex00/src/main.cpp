#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("noobi");
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		a.attack("training bot");
		a.takeDamage(4);
		a.beRepaired(2);
		std::cout << std::endl;
	}
	return (0);
}
