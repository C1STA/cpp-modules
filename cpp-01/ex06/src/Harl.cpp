#include <iostream>
#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl << "I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<"I think I deserve to have some extra bacon for free." << std::endl << "I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i;

	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break ;
	}

	switch (i)
	{
		case 0:
			debug();
			/* fall through */
		case 1:
			if (i != 1)
				std::cout << std::endl;
			info();
			/* fall through */
		case 2:
			if (i != 2)
				std::cout << std::endl;
			warning();
			/* fall through */
		case 3:
			if (i != 3)
				std::cout << std::endl;
			error();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
