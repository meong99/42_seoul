#include "phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	command;
	while (1)
	{
		std::cout << "Enter command!\n";
		std::cin >> command;
		phonebook.command_add();
	}
	return (0);
}