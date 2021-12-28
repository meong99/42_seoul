#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) {}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_slot[i];
		this->_slot[i] = NULL;
	}
}

Character::Character(const Character &ref)
{
	this->_name = ref._name;
	for (int i = 0; i < 4; i++)
	{
		if (ref._slot[i])
			this->_slot[i] = ref._slot[i]->clone();
		else
			this->_slot[i] = NULL;
	}
}

Character	&Character::operator=(const Character &ref)
{
	this->_name = ref._name;
	for (int i = 0; i < 4; i++)
	{
		if (ref._slot[i])
			this->_slot[i] = ref._slot[i]->clone();
		else
			this->_slot[i] = NULL;
	}
	return (*this);
}

Character::Character(const std::string &name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int	idx)
{
	if (0 <= idx && idx <= 4)
		this->_slot[idx] = NULL;
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::use(int idx, ICharacter &target)
{
	if (0 <= idx && idx <= 4)
		this->_slot[idx]->use(target);
}