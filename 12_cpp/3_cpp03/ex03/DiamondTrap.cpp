# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_diaName << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), FragTrap(ref), ScavTrap(ref)
{
	this->_diaName = ref._diaName;
	if (this->ClapTrap::_name.find("_Clap_name") == false)
		this->ClapTrap::_name += "_Clap_name";
	std::cout << "DiamondTrap " << this->_diaName << " created" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->FragTrap::operator=(ref);
	this->ScavTrap::operator=(ref);
	this->_diaName = ref._diaName;
	this->_hp = ref._hp;
	this->_ep = ref._ep;
	this->_ad = ref._ad;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_Clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_diaName = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 30;
	std::cout << "DiamondTrap " << this->_diaName << " created" << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_diaName;
	std::cout << " And ClapTrap name is " << this->ClapTrap::_name << std::endl;
}