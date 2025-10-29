#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int			N = 5;

	horde = zombieHorde(N, "Ken");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl << "Pointer value for zombie[" << i << "]: " << &horde[i] << std::endl;
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
