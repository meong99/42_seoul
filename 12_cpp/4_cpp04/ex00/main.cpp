#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
    const Animal* pAnimal = new Animal();
    const Animal* pDog = new Dog();
    const Animal* pCat = new Cat();
	std::cout << pDog->getType() << " " << std::endl;
	pDog->makeSound();
	std::cout << pCat->getType() << " " << std::endl;
	pCat->makeSound();
	std::cout << pAnimal->getType() << " " << std::endl;
	pAnimal->makeSound();

	delete pAnimal;
	delete pDog;
	delete pCat;
	std::cout << std::endl << "-----------except virtual keyword-----------" << std::endl << std::endl;

	const WrongAnimal *pWanimal = new WrongAnimal();
	const WrongAnimal *pWcat = new WrongCat();
	std::cout << pWcat->getType() << " " << std::endl;
	pWcat->makeSound();
	std::cout << pWanimal->getType() << " " << std::endl;
	pWanimal->makeSound();

	delete pWanimal;
	delete pWcat;
}