#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hp(10), _ep(10), _ad(0), _name(name)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) : _hp(ref._hp), _ep(ref._ep), _ad(ref._ad), _name(ref._name)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ref)
{
	this->_name = ref._name;
	this->_hp = ref._hp;
	this->_ep = ref._ep;
	this->_ad = ref._ad;
	return (*this);
}

bool	ClapTrap::deathCheck(void)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return (true);
	}
	return (false);
}

bool	ClapTrap::lowEp(void)
{
	if (this->_ep < 5)
	{
		std::cout << this->_name << "'s not enough ep" << std::endl;
		return (true);
	}
	return (false);
}


void	ClapTrap::attack(std::string const &target)
{
	if (lowEp() == true)
		return ;
	
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 5;
	std::cout << this->_name << "'s ep left " << this->_ep << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (deathCheck() == true)
		return ;

	std::cout << "ClapTrap " << this->_name << " got " << amount << " damage" << std::endl;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (deathCheck() == true)
		return ;

	std::cout << "ClapTrap " << this->_name << "'s hp has recovered by " << amount << "!" << std::endl;
	this->_hp += amount;
	std::cout << this->_name << "'s hp left " << this->_hp << std::endl;
}