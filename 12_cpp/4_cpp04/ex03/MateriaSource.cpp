#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_learned[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_learned[i];
		this->_learned[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i])
			this->_learned[i] = ref._learned[i]->clone();
		else
			this->_learned[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i])
			this->_learned[i] = ref._learned[i]->clone();
		else
			this->_learned[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] == NULL)
		{
			this->_learned[i] = materia;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i]->getType() == type)
			return (this->_learned[i]->clone());
	}
	return (0);
}