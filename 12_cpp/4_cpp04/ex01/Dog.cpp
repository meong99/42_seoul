#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_dogsBrain = new Brain(this->_type);
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_dogsBrain;
	std::cout << "Destroy " << this->_type << "class" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal()
{
	this->_type = ref._type;
	this->_dogsBrain = new Brain(*ref._dogsBrain);
	std::cout << "Create " << this->_type << "class" << std::endl;
}

Dog	&Dog::operator=(const Dog &ref)
{
	this->_type = ref._type;
	this->_dogsBrain = new Brain(*ref._dogsBrain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "bowwwwwwwwww~~~~~~~wowwwwwwwwwwwwwwwwww~~~" << std::endl;
}

Brain	*Dog::getBrain(void)
{
	return (this->_dogsBrain);
}