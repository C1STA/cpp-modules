#include "Zombie.hpp"

int	main()
{
	try
	{
		std::cout << "*** zombie on the heap ***" << std::endl << std::endl;
		Zombie	*z1 = newZombie("Michael");
		z1->announce();
		delete z1;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "*** zombie on the stack ***" << std::endl << std::endl;
	randomChump("Brandon");
	return (0);
}
