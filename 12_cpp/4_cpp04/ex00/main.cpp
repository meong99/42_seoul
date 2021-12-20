#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
    const Animal* pAnimal = new Animal();
    const Animal* pA_dog = new Dog();
    const Animal* pA_cat = new Cat();
	std::cout << pA_dog->getType() << " " << std::endl;
	pA_dog->makeSound();
	std::cout << pA_cat->getType() << " " << std::endl;
	pA_cat->makeSound();
	std::cout << pAnimal->getType() << " " << std::endl;
	pAnimal->makeSound();

	std::cout << std::endl << "-----------except virtual keyword-----------" << std::endl << std::endl;

	const WrongAnimal *pWanimal = new WrongAnimal();
	const WrongAnimal *pWcat = new WrongCat;
	std::cout << pWcat->getType() << " " << std::endl;
	pWcat->makeSound();
	std::cout << pWanimal->getType() << " " << std::endl;
	pWanimal->makeSound();
}