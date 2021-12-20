#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (lowEp() == true)
		return ;
	
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 5;
	std::cout << this->_name << "'s ep left " << this->_ep << std::endl;
}
