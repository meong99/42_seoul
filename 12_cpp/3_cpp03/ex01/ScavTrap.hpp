#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap(void);
	~ScavTrap(void);
	ScavTrap(std::string name, int hp, int ep, int ad);
	ScavTrap	&operator=(const ScavTrap &ref);

	void	guardGate(void);
};

#endif