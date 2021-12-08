#include "Zombie.hpp"

int	main(void)
{
	Zombie		zombie;
	std::string	ranName[5] = {"xox", "o_o", "0-0", "oyo", "oxo"};

	std::srand((unsigned int)std::time(NULL));
	zombie.announce();

	randomChump( ranName[rand() % 5] );

	Zombie* p_zombie = newZombie( "bobo" );
	p_zombie->announce();
	delete p_zombie;
}