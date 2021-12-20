#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap(void);
	
public:
	~FragTrap(void);
	FragTrap(const FragTrap &ref);
	FragTrap	&operator=(const FragTrap &ref);
	FragTrap(std::string name);

	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys(void);
};


#endif