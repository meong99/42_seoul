#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie;

	zombie.announce();

	Zombie::randomChump( "fool");

	Zombie* p_zombie = Zombie::newZombie( "bobo" );
	p_zombie->announce();
	delete p_zombie;
}