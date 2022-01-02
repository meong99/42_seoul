#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain* _catsBrain;
	
public:
	Cat(void);
	virtual ~Cat(void);
	Cat(const Cat &ref);
	Cat	&operator=(const Cat &ref);

	virtual void	makeSound(void) const;
	virtual Brain		*getBrain(void);
};


#endif