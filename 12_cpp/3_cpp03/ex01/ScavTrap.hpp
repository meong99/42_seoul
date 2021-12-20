#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap(void);
	
public:
	~ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ref);
	ScavTrap	&operator=(const ScavTrap &ref);

	void	guardGate(void);
	void	attack(std::string const & target);
};

#endif