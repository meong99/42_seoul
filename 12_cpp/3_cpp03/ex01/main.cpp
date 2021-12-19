#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	champ_1("Timo", 20, 10, 5);

	champ_1.attack("worm");
	champ_1.takeDamage(15);
	champ_1.beRepaired(10);
	champ_1.takeDamage(15);
	champ_1.takeDamage(15);

	std::cout << std::endl << "--------------Next chapter--------------" << std::endl << std::endl;

	ClapTrap	champ_2;

	champ_2.attack("kkong");
	champ_2.takeDamage(15);
	champ_2.beRepaired(10);
	champ_2.takeDamage(15);
	champ_2.takeDamage(15);
}