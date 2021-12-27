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

	const std::string	&getType( void ) const;
	void		setType( std::string str );
};

#endif
