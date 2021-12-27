#include "Weapon.hpp"

Weapon::Weapon( void ) {}
Weapon::~Weapon( void ) {}
Weapon::Weapon( std::string type ):_type(type) {}

const std::string	&Weapon::getType( void ) const
{
	return (_type);
}

void	Weapon::setType( std::string str )
{
	_type = str;
}
