#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
private:

protected:
	std::string	_type;
public:
	WrongAnimal(void);
	~WrongAnimal(void);
	WrongAnimal(const WrongAnimal &ref);
	WrongAnimal	&operator=(const WrongAnimal &ref);

	void		makeSound(void) const;
	std::string const	&getType(void) const;
};

#endif