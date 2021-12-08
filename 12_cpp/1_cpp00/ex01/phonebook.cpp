#include "phonebook.hpp"

Phonebook::Phonebook( void )
{
	_index = 0;
	is_working = true;
	std::cout << MAGENTA << "Hello !" << RESET << std::endl;
}

Phonebook::~Phonebook( void )
{
	std::cout << MAGENTA << "Bye !" << RESET << std::endl;
}

void Phonebook::_exitPhonebook( void )
{
	is_working = false;
}

void Phonebook::enter_command( std::string &command )
{
	std::cout << GREEN << "Enter command :" << RESET << std::endl;
	std::cin >> command;
}

void Phonebook::run_command( const std::string command )
{
	if (command == "EXIT" || command == "exit")
		_exitPhonebook();
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
}
