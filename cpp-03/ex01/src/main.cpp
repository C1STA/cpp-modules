#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a("A");
	ScavTrap	b("B");

	a.guardGate();
	for (int i = 0; i < 51; i++)
	{
		a.attack("B");
		b.takeDamage(20);
	}
	return (0);
}
