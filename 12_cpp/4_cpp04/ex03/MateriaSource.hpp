#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_learned[4];

public:
	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource(const MateriaSource &ref);
	MateriaSource	&operator=(const MateriaSource &ref);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif