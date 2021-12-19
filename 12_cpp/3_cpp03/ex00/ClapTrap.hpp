#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_ad;

public:
	ClapTrap(void);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &ref);
	ClapTrap(std::string name, int hp, int ep, int ad);
	ClapTrap	&operator=(const ClapTrap &ref);

	bool	deathCheck(void);
	bool	lowEp(void);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif