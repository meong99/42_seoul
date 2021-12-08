#include "phonebook.hpp"

int main( void )
{
	Phonebook	phonebook;
	std::string	command;
	bool		is_working = true;

	while (is_working)
	{
		phonebook.enter_command(command);
		is_working = phonebook.run_command(command);
	}
	return (0);
}