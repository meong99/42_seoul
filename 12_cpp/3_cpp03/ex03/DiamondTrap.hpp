#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	DiamondTrap(void);
	std::string	_diaName;
	
public:
	~DiamondTrap(void);
	DiamondTrap(const DiamondTrap &ref);
	DiamondTrap	&operator=(const DiamondTrap &ref);
	DiamondTrap(std::string name);

	void	attack(std::string const & target);
	void	whoAmI(void);
};


#endif