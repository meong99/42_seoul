#include "Dog.hpp"
#include "Cat.hpp"
#include <unistd.h>

int	main(void)
{
	Animal	*arr_animals[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i < 5)
			arr_animals[i] = new Dog();
		else
			arr_animals[i] = new Cat();
	}

	std::cout << std::endl << "----------delete----------" << std::endl << std::endl;

	for (size_t i = 0; i < 10; i++)
		delete arr_animals[i];

	system("leaks Brain");

	std::cout << std::endl << "----------check dog's deep copy----------" << std::endl << std::endl;
	
	Dog	dogtest;
	sleep(1);
	Dog	dogtest_2 = dogtest;
	sleep(1);
	Dog	dogtest3;
	dogtest.getBrain()->setIdea(0, "😎");
	for (size_t i = 0; i < 50; i++)
		std::cout << dogtest.getBrain()->getIdea(i);
	std::cout << std::endl;
	for (size_t i = 0; i < 50; i++)
		std::cout << dogtest_2.getBrain()->getIdea(i);
	std::cout << std::endl;
	for (size_t i = 0; i < 50; i++)
		std::cout << dogtest3.getBrain()->getIdea(i);
	std::cout << std::endl;

	std::cout << std::endl << "----------check cat's deep copy----------" << std::endl << std::endl;

	Cat	cattest;
	sleep(1);
	Cat	cattest_2 = cattest;
	sleep(1);
	Cat	cattest3;
	cattest.getBrain()->setIdea(0, "🤬");
	for (size_t i = 0; i < 50; i++)
		std::cout << cattest.getBrain()->getIdea(i);
	std::cout << std::endl;
	for (size_t i = 0; i < 50; i++)
		std::cout << cattest_2.getBrain()->getIdea(i);
	std::cout << std::endl;
	for (size_t i = 0; i < 50; i++)
		std::cout << cattest3.getBrain()->getIdea(i);
	std::cout << std::endl;

	system("leaks Brain");
}