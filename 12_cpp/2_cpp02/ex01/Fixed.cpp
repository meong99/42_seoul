#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void):_fixedPointNum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNum = num << _fractional;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNum = (int)roundf(num * (1 << _fractional));
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

std::ostream	&operator<<(std::ostream &out, const Fixed &ref)
{
	out << ref.toFloat();

	return (out);
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

int		Fixed::toInt(void) const
{
	return (_fixedPointNum >> _fractional);
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointNum / (1 << _fractional));
}