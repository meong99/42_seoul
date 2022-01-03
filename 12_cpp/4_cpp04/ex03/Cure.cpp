#include "Cure.hpp"

Cure::Cure(void):AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(const Cure &ref):AMateria(ref) {}

Cure	&Cure::operator=(const Cure &ref)
{
	this->_type = ref._type;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}