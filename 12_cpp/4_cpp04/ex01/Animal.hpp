#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
private:

protected:
	std::string	_type;
public:
	Animal(void);
	virtual ~Animal(void);
	Animal(const Animal &ref);
	Animal	&operator=(const Animal &ref);

	virtual void		makeSound(void) const;
	std::string const	&getType(void) const;
	virtual const Brain		*getBrain(void) const = 0;
};

#endif