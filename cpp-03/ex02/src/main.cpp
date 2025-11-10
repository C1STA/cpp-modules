#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	claptrap1("Robot1");
	ClapTrap	claptrap2("Robot2");

	ScavTrap	scavtrap1("Guard1");
	ScavTrap	scavtrap2("Guard2");

	FragTrap	fragtrap1("Fragger1");
	FragTrap	fragtrap2("Fragger2");

	claptrap1.attack("Target");
	scavtrap1.attack("Target");
	fragtrap1.attack("Target");

	scavtrap1.guardGate();
	fragtrap1.highFivesGuys();

	return (0);
}
