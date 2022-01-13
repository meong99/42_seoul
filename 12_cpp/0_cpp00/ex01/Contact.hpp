#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	_infos[8][5];
public:
	void		AddContact(const std::string	_infomation[5]);
	void		PrintInfo(int index);
	std::string	*GetInfo(int index);
};

#endif