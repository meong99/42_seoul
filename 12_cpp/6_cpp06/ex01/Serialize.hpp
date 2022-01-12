#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>

typedef struct	s_Data
{
	std::string	name;
	std::string	hobby;
}				t_Data;

uintptr_t	serialize(t_Data* ptr);
t_Data*		deserialize(uintptr_t raw);

#endif