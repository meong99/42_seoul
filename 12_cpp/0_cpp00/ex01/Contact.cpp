#include "Contact.hpp"

void	Contact::AddContact(const std::string	_infomation[5])
{
	for (int i = 0; i < 8; i++)
	{
		if (_infos[i][0] == "")
		{
			for (int j = 0; j < 5; j++)
				_infos[i][j] = _infomation[j];
			break;
		}
		if (i == 7)
		{
			for (int j = 0; j < 7; j++)
			{
				for (int k = 0; k < 5; k++)
					_infos[j][k] = _infos[j + 1][k];
			}
			for (int k = 0; k < 5; k++)
				_infos[7][k] = _infomation[k];
		}
	}
}

void	Contact::PrintInfo(int index)
{
	for (int i = 0; i < 5; i++)
		std::cout << _infos[index][i] << std::endl;
	std::cout << std::endl;
}

std::string	*Contact::GetInfo(int index)
{
	return (_infos[index]);
}