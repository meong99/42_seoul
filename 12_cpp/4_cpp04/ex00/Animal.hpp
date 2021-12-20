#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
private:

protected:
	std::string	_type;
public:
	Animal(void);
	~Animal(void);
	Animal(const Animal &ref);
	Animal	&operator=(const Animal &ref);

	virtual void		makeSound(void) const;
	std::string const	&getType(void) const;
};

#endif