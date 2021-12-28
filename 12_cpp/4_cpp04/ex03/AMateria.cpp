#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::~AMateria(void) {}

AMateria::AMateria(const AMateria &ref):_type(ref._type){}

AMateria	&AMateria::operator=(const AMateria &ref)
{
	this->_type = ref._type;
	return (*this);
}

AMateria::AMateria(std::string const &type):_type(type) {}
std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	target.getName();
}