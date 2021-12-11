#include "HumanB.hpp"

HumanB::HumanB( std::string name, Weapon *weapon ):_name(name), _weapon(weapon) {}
HumanB::HumanB( std::string name ):_name(name), _weapon(NULL) {}
HumanB::~HumanB( void ) {}

void	HumanB::attack( void )
{
	if (_weapon)
		std::cout << _name << " attacks with his " << (*_weapon).getType() << std::endl;
	else
		std::cout << _name << " doesn't have weapon" << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	_weapon = &weapon;
}
