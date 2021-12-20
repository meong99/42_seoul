#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	if (lowEp() == true)
		return ;
	
	std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 5;
	std::cout << this->_name << "'s ep left " << this->_ep << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High five!!" << std::endl;
}
