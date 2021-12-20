#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "FragTrap created" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "FragTrap created" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "FragTrap created" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	if (lowEp() == true)
		return ;
	
	std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 5;
	std::cout << this->_name << "'s ep left " << this->_ep << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (deathCheck() == true)
		return ;

	std::cout << "FragTrap " << this->_name << " got " << amount << " damage" << std::endl;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (deathCheck() == true)
		return ;

	std::cout << "FragTrap " << this->_name << "'s hp has recovered by " << amount << "!" << std::endl;
	this->_hp += amount;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}