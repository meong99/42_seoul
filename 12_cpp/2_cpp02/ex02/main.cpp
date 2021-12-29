#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;


	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;
	
	std::cout << "max = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min = " << Fixed::min( a, b ) << std::endl;

	std::cout << std::endl;

	std::cout << "5.0 < 4.0 = " << (Fixed(5.0f) < Fixed(4.0f)) << std::endl;
	std::cout << "5.0 > 4.0 = " << (Fixed(5.0f) > Fixed(4.0f)) << std::endl;
	std::cout << "5.0 <= 4.0 = " << (Fixed(5.0f) <= Fixed(4.0f)) << std::endl;
	std::cout << "5.0 >= 4.0 = " << (Fixed(5.0f) >= Fixed(4.0f)) << std::endl;
	std::cout << "4.0 == 4.0 = " << (Fixed(4.0f) == Fixed(4.0f)) << std::endl;
	std::cout << "4.0 != 4.0 = " << (Fixed(4.0f) != Fixed(4.0f)) << std::endl;
	std::cout << "4.2 + 2.0 = " << (Fixed(4.2f) + Fixed(2.0f)) << std::endl;
	std::cout << "4.2 - 2.0 = " << (Fixed(4.2f) - Fixed(2.0f)) << std::endl;
	std::cout << "4.2 * 2.0 = " << (Fixed(4.2f) * Fixed(2.0f)) << std::endl;
	std::cout << "4.2 / 2.0 = " << (Fixed(4.2f) / Fixed(2.0f)) << std::endl;
	return 0;
}