#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):ClapTrap("", 0, 0, 0)
{
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SavTrap destroyed" << std::endl;
}

ScavTrap::ScavTrap(std::string name, int hp, int ep, int ad):ClapTrap(name, hp, ep, ad)
{
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}
