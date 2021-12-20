#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	ScavTrap(void);

public:
	~ScavTrap(void);
	ScavTrap(const ScavTrap &ref);
	ScavTrap	&operator=(const ScavTrap &ref);
	ScavTrap(std::string name);

	void	guardGate(void);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif