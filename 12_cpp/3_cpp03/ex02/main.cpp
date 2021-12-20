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

	std::cout << std::endl << "--------------Next chapter--------------" << std::endl << std::endl;

	FragTrap	champ_2 = champ_1;

	champ_2.attack("kkong");
	champ_2.takeDamage(15);
	champ_2.beRepaired(10);
	champ_2.takeDamage(15);
	champ_2.takeDamage(15);
	champ_2.highFivesGuys();
}