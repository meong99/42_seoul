#include "Zombie.hpp"

int	main(void)
{
	int		num = 5;
	Zombie*	zombies = zombieHorde(num, "zombies");

	if (zombies == NULL)
		return (1);

	for (int i = 0; i < num; i++)
		zombies[i].announce();
	delete []zombies;
}