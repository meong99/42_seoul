#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &ref);
	Cat	&operator=(const Cat &ref);

	virtual void	makeSound(void) const;
};


#endif