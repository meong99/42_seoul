#include "Karen.hpp"

Karen::Karen(void) {}
Karen::~Karen(void) {}

void	Karen::complain( std::string level )
{
	std::string	arrlev[4] = { 
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
		};

	void	(Karen::*func[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	bool	allowPrinting = false;
	for (int i = 0; i < 4; i++)
	{
		if (arrlev[i] == level || allowPrinting == true)
		{
			(this->*func[i])();
			allowPrinting = true;	
		}
	}
	if (allowPrinting == false)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		std::cout << "There are many ways to filter karen, but one of the best ones is to SWITCH her off" << std::endl;
	}
}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << " I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
