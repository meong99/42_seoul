#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap created" << std::endl;
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
	std::cout << "ScavTrap created" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (lowEp() == true)
		return ;
	
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 5;
	std::cout << this->_name << "'s ep left " << this->_ep << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (deathCheck() == true)
		return ;

	std::cout << "ScavTrap " << this->_name << " got " << amount << " damage" << std::endl;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (deathCheck() == true)
		return ;

	std::cout << "ScavTrap " << this->_name << "'s hp has recovered by " << amount << "!" << std::endl;
	this->_hp += amount;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}