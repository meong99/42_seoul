#include "Add.hpp"

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

void	Add::add( Contact &contact, int &_index )
{
	if (_getInfo())
	{
		contact.AddContact(_infomation);
		std::cout << YELLOW << "input complete !" << RESET << std::endl << std::endl;
		if ( _index < 8 )
			_index++;
	}
}
