#ifndef ADD_HPP
# define ADD_HPP

# include "color.h"
# include <iostream>

class Add
{
private	:
	std::string	_infomation[5];

	void	_getInfo( void );
	void	_putInfo( std::string (&_infos)[8][5] );
public	:
	void	add( std::string (&_infos)[8][5], int &_index );
};

#endif