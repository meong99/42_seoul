#include "Fixed.hpp"

int	main(void)
{
	Fixed	first;
	std::cout << first.getRawBits() << std::endl;
	first.setRawBits(1);
	std::cout << first.getRawBits() << std::endl;
	
	Fixed	second(first);
	first.setRawBits(2);
	Fixed	third(first);
	std::cout << second.getRawBits() << std::endl;
	std::cout << third.getRawBits() << std::endl;

	second = third;
	std::cout << second.getRawBits() << std::endl;
	std::cout << third.getRawBits() << std::endl;
}