#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	this->_catsBrain = new Brain(this->_type);
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_catsBrain;
	std::cout << "Destroy " << this->_type << "class" << std::endl;
}

Cat::Cat(const Cat &ref) : Animal()
{
	this->_type = ref._type;
	this->_catsBrain = new Brain(*ref._catsBrain);
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Cat	&Cat::operator=(const Cat &ref)
{
	this->_type = ref._type;
	this->_catsBrain = new Brain(*ref._catsBrain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwwwwwwwwwwwww~~~" << std::endl;
}

Brain	*Cat::getBrain(void)
{
	return (this->_catsBrain);
}