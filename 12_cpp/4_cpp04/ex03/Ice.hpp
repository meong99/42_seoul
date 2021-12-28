#ifndef ICE
# define ICE

# include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice(void);
	~Ice(void);
	Ice(const Ice &ref);
	Ice	&operator=(const Ice &ref);

	virtual AMateria* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif