#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	int			_hp;
	int			_ep;
	int			_ad;
	std::string	_name;

public:
	ClapTrap(void);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &ref);
	ClapTrap(std::string name);
	ClapTrap	&operator=(const ClapTrap &ref);

	bool	deathCheck(void);
	bool	lowEp(void);
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif