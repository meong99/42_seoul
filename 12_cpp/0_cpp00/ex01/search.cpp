#include "Search.hpp"

void Search::_print_list(std::string str[], std::string color = WHITE, int index = 0)
{
	std::string infostr[4] = {
		"index",
		"last name",
		"first name",
		"nick name"};

	if (index == 0)
		_print_list(infostr, CYAN, -1);
	std::cout << "|";
	if (index == -1)
		std::cout << color << std::setw(10) << "index" << RESET << "|";
	else
		std::cout << color << std::setw(10) << index << RESET << "|";
	for (int j = 0; j < 3; j++)
	{
		if (str[j].length() > 10)
			std::cout << color << std::setw(9) << str[j].substr(0, 9) << "." << RESET << "|";
		else
			std::cout << color << std::setw(10) << str[j] << RESET << "|";
	}
	std::cout << std::endl;
}

void Search::search(Contact contect[8], int _index)
{
	std::cout << GREEN << "Contact list !" << RESET << std::endl;
	if (contect[0].IsEmpty())
	{
		std::cout << RED << "Add first ! " << RESET << std::endl;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (contect[i].IsEmpty() == false)
			_print_list(contect[i].GetInfo(), WHITE, i);
	}
	std::cout << GREEN << "Enter index of information you want to print out !" << RESET << std::endl;

	int index;

	while (!(std::cin >> index) || (index < 0 || index > 8) || index >= _index)
	{
		std::cin.clear();
		clearerr(stdin);
		fflush(stdin);
		std::cout << RED << "Wrong input !" << RESET << std::endl;
		std::cout << GREEN << "Enter index of information you want to print out !" << RESET << std::endl;
	}
	contect[index].PrintInfo();
}
