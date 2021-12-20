#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "Create " << this->_type << "class" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destroy " << this->_type << "class" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal()
{
	this->_type = ref._type;
	std::cout << "Create " << this->_type << "class" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &ref)
{
	this->_type = ref._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong~~~~~~~Cat~~~" << std::endl;
}
