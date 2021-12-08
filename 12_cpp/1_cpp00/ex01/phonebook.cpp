#include "phonebook.hpp"

Phonebook::Phonebook( void )
{
	_index = 0;
	std::cout << MAGENTA << "Hello !" << RESET << std::endl;
}

Phonebook::~Phonebook( void )
{
	std::cout << MAGENTA << "Bye !" << RESET << std::endl;
}

bool Phonebook::_exitPhonebook( void )
{
	return ( false );
}

void Phonebook::enter_command( std::string &command )
{
	std::cout << GREEN << "Enter command :" << RESET << std::endl;
	std::cin >> command;
}

bool Phonebook::run_command( const std::string command )
{
	bool	is_working = true;

	if (command == "EXIT" || command == "exit")
		is_working = _exitPhonebook();
	else if (command == "ADD" || command == "add")
		_add.add(_infos, _index);
	else if (command == "SEARCH" || command == "search")
		_search.search(_infos, _index);
	else
	{
		if (std::cin.eof() == true)
		{
			std::cin.clear();
			clearerr(stdin);
		}
		std::cout << RED << "Can't found command !" << RESET << std::endl;
	}
	return ( is_working );
}
