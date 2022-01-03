#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria(void);
	virtual ~AMateria(void);
	AMateria(const AMateria &ref);
	AMateria(std::string const & type);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif