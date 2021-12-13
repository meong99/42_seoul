#include "Fixed.hpp"

Fixed::Fixed(void):_fixedPointNum(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy):_fixedPointNum(copy._fixedPointNum) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	std::cout << "Assignation operator called" << std::endl;
	_fixedPointNum = ref._fixedPointNum;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointNum = raw;
}
