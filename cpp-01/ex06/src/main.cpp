#include <iostream>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
	{
		harl.complain("DEBUG");
		std::cout << "---------------------------------------------------------" << std::endl << std::endl;
		harl.complain("INFO");
		std::cout << "---------------------------------------------------------" << std::endl << std::endl;
		harl.complain("WARNING");
		std::cout << "---------------------------------------------------------" << std::endl << std::endl;
		harl.complain("ERROR");
		std::cout << "---------------------------------------------------------" << std::endl << std::endl;
		harl.complain("UNKNWON");
		std::cout << std::endl;
	}
	return (0);
}
