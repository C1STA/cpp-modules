#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombie = 0;

	if (N <= 0)
	{
		std::cerr << "N("  << N << ") must be superior to zero." << std::endl;
		return (zombie);
	}
	try
	{
		zombie = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombie[i].setName(name);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		delete[] zombie;
		zombie = 0;
	}
	return (zombie);
}
