#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	champ_1("Timo");

	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.beRepaired(10);
	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.takeDamage(15);
	champ_1.guardGate();
	std::cout << std::endl;
	ScavTrap	champ_2 = champ_1;
	champ_2.takeDamage(1);

	return (0);
}