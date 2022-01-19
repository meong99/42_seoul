#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "Create " << this->_type << "class" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destroy " << "WrongAnimal(" << this->_type << ")" << "class" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) : _type(ref._type)
{
	std::cout << "Create " << this->_type << "class" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &ref)
{
	this->_type = ref._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong~~~~~~~Animalllllllllll~~~" << std::endl;
}

std::string const	&WrongAnimal::getType(void) const
{
	return (this->_type);
}