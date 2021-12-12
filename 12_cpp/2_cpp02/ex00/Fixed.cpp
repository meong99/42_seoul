#include "Fixed.hpp"

Fixed::Fixed(void):_fixedPointNum(0) {
	std::cout << "Called default constructor" << std::endl;
}
Fixed::~Fixed(void) {
	std::cout << "Called destructor" << std::endl;
}
Fixed::Fixed(const Fixed &copy):_fixedPointNum(copy._fixedPointNum) {
	std::cout << "Called copy constructor" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	std::cout << "Called assignation operator overload" << std::endl;
	_fixedPointNum = ref._fixedPointNum;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointNum = raw;
}
