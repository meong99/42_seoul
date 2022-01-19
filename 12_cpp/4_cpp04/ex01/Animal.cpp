#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Destroy " << "Animal(" << this->_type << ")" << "class" << std::endl;
}

Animal::Animal(const Animal &ref) : _type(ref._type)
{
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Animal	&Animal::operator=(const Animal &ref)
{
	this->_type = ref._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animalllllllllll~~~" << std::endl;
}

std::string const	&Animal::getType(void) const
{
	return (this->_type);
}