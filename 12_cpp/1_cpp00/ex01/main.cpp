#include "phonebook.hpp"

int main( void )
{
	Phonebook	phonebook;
	std::string	command;

	while (phonebook.is_working)
	{
		phonebook.enter_command(command);
		phonebook.run_command(command);
	}
	return (0);
}