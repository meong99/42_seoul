#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_slot[4];
	Character();

public:
	~Character();
	Character(const Character &ref);
	Character	&operator=(const Character &ref);
	Character(const std::string &name);

	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual std::string const & getName() const;
	virtual void use(int idx, ICharacter& target);
};

#endif