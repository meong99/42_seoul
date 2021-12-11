#include "add.hpp"

void	Add::_putInfo( std::string (&_infos)[8][5] )
{
	for (int i = 0; i < 8; i++)
	{
		if (_infos[i][0] == "")
		{
			for (int j = 0; j < 5; j++)
				_infos[i][j] = _infomation[j];
			break;
		}
		if (i == 7)
		{
			for (int j = 0; j < 7; j++)
			{
				for (int k = 0; k < 5; k++)
					_infos[j][k] = _infos[j + 1][k];
			}
			for (int k = 0; k < 5; k++)
				_infos[7][k] = _infomation[k];
		}
	}
}

bool	Add::_getInfo( void )
{
	std::string infostr[5] = {
		"last name : ",
		"fisrt name : ",
		"nick name : ",
		"phonenumber : ",
		"secret : "};

	std::cout << GREEN << "Enter information !" << RESET << std::endl;
	for ( int i = 0; i < 5; i++ )
	{
		std::cout << CYAN << infostr[i] << RESET << std::endl;
		std::cin >> _infomation[i];
		if ( std::cin.eof() == true )
		{
			std::cin.clear();
			clearerr( stdin );
			return ( false );
		}
	}
	return ( true );
}

void	Add::add( std::string ( &_infos )[8][5], int &_index )
{
	if (_getInfo())
	{
		_putInfo( _infos );
		std::cout << YELLOW << "input complete !" << RESET << std::endl << std::endl;
		if ( _index < 8 )
			_index++;
	}
}
