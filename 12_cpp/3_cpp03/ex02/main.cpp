#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	champ_1("Timo");

	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.beRepaired(10);
	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.takeDamage(15);
	champ_1.highFivesGuys();
}