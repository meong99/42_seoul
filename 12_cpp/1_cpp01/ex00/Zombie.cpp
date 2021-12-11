#include "Zombie.hpp"

Zombie::Zombie( void ):_name("noname") {}

Zombie::Zombie( std::string name ):_name( name ) {}

Zombie::~Zombie( void )
{
	std::cout << _name << " x_x ..." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName( void )
{
	return ( _name );
}
