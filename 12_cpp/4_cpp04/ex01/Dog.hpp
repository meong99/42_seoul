#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain* _dogsBrain;
	
public:
	Dog(void);
	virtual ~Dog(void);
	Dog(const Dog &ref);
	Dog	&operator=(const Dog &ref);
	
	virtual void	makeSound(void) const;
	virtual const Brain		*getBrain(void) const;
};


#endif