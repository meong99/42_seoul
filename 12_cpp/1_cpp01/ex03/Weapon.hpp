#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );

	std::string	&getType( void );
	void		setType( std::string str );
};

#endif
