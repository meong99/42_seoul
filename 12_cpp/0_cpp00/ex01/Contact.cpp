#include "Contact.hpp"

void	Contact::AddContact(const std::string	_infomation[5])
{
	for (int i = 0; i < 5; i++)
		_infos[i] = _infomation[i];
}

void	Contact::PrintInfo(void)
{
	for (int i = 0; i < 5; i++)
		std::cout << _infos[i] << std::endl;
	std::cout << std::endl;
}

std::string	*Contact::GetInfo(void)
{
	return (_infos);
}

bool	Contact::IsEmpty(void)
{
	if (_infos[0] == "")
		return (true);
	return (false);
}