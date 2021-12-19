#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name(""), _hp(20), _ep(10), _ad(0)
{
	std::cout << "ClapTrap created" << std::endl;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destroyed" << std::endl;
}
ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad):_name(name), _hp(hp), _ep(ep), _ad(ad) {}
ClapTrap	&ClapTrap::operator=(const ClapTrap &ref)
{
	this->_name = ref._name;
	this->_hp = ref._hp;
	this->_ep = ref._ep;
	this->_ad = ref._ad;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " already died" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " got " << amount << " damage" << std::endl;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << "already died" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << "'s hp has recovered by " << amount << "!" << std::endl;
	this->_hp += amount;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}