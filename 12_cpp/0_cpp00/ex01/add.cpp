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

void	Add::_addInfoToContact(Contact contact[8])
{
	for (int i = 0; i < 8; i++)
	{
		if (contact[i].IsEmpty())
		{
			contact[i].AddContact(_infomation);
			return ;
		}
		if (i == 7)
		{
			for (int j = 0; j < 7; j++)
			{
				contact[j].AddContact(contact[j + 1].GetInfo());
			}
			contact[7].AddContact(_infomation);
		}
	}
}

int	Add::add( Contact contact[8], int _index )
{
	if (_getInfo())
	{
		_addInfoToContact(contact);
		std::cout << YELLOW << "input complete !" << RESET << std::endl << std::endl;
		if ( _index < 8 )
			return (1);
	}
	return (0);
}
