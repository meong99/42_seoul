#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Destroy " << this->_type << "class" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal()
{
	this->_type = ref._type;
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Dog	&Dog::operator=(const Dog &ref)
{
	this->_type = ref._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "bowwwwwwwwww~~~~~~~wowwwwwwwwwwwwwwwwww~~~" << std::endl;
}
