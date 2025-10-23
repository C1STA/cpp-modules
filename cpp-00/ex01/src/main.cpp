#include "Contact-class.hpp"
#include "PhoneBook-class.hpp"

int	main()
{
	PhoneBook		Repository;
	std::string	cmd;

	std::cout << "Welcome to your awesome phonebook !" << std::endl;
	std::cout << "Available commands are : ADD, SEARCH and EXIT" << std::endl;
	while (true)
	{
		std::cout << "PhoneBook: ";
		if (!std::getline(std::cin, cmd))
			return (std::cout << "Wrong input!" << std::endl, 1);
		if (cmd == "ADD")
			Repository.add();
		else if (cmd == "SEARCH")
			Repository.search();
		else if (cmd == "EXIT")
				return std::cout << "Exiting." << std::endl, 0;
	}
	return (0);
}
