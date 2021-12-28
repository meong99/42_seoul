#include "Ice.hpp"

Ice::Ice(void):AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(const Ice &ref):AMateria(ref._type) {}

Ice	&Ice::operator=(const Ice &ref)
{
	this->_type = ref._type;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an "<< this->_type << " bolt at " << target.getName() << " *" << std::endl;
}