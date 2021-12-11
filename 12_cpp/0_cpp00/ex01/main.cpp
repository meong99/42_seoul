#include "phonebook.hpp"

int main( void )
{
	Phonebook	phonebook;
	std::string	command;
	bool		is_working = true;

	while (is_working)
	{
		std::cout << GREEN << "Enter command :" << RESET << std::endl;
		std::cin >> command;
		is_working = phonebook.run_command(command);
		command = "";
	}
	return (0);
}