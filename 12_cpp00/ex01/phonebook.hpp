#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
class Phonebook
{
private	:
	std::string	infomation[5];
public	:
	Phonebook();
	~Phonebook();
	void	command_add();
	void	command_exit();
	void	command_search();
};

Phonebook::Phonebook()
{
	std::cout << "Hello ! Enter command !\n";
}

Phonebook::~Phonebook()
{
	std::cout << "Bye !\n";
}

void	Phonebook::command_add()
{
	std::string	infostr[5] = {"last name : ", "fisrt name : ", "nick name : ", "phonenumber : ", "secret : "};

	std::cout << "Enter information !\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << infostr[i];
		std::cin >> infomation[i];
	}
	std::cout << "input complete\n";
}


#endif