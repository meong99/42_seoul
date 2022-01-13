#ifndef ADD_HPP
# define ADD_HPP

# include "color.h"
# include <iostream>
# include "Contact.hpp"

class Add
{
private	:
	std::string	_infomation[5];

	bool	_getInfo( void );
	void	_addInfoToContact(Contact contact[]);
public	:
	int	add( Contact contact[8], int _index );
};

#endif