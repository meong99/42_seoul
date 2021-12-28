#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure();
	~Cure();
	Cure(const Cure &ref);
	Cure	&operator=(const Cure &ref);

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif