#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Destroy " << this->_type << "class" << std::endl;
}

Cat::Cat(const Cat &ref) : Animal()
{
	this->_type = ref._type;
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Cat	&Cat::operator=(const Cat &ref)
{
	this->_type = ref._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwwwwwwwwwwwww~~~" << std::endl;
}
