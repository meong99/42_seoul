#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	champ_1("Timo");

	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.beRepaired(10);
	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.takeDamage(15);
	champ_1.guardGate();
	champ_1.highFivesGuys();

	std::cout << std::endl;

	DiamondTrap	champ_2 = champ_1;
	champ_1.takeDamage(10);
}