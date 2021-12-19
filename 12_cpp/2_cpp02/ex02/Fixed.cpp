#include "Fixed.hpp"

Fixed::Fixed(void):_fixedPointNum(0) {}

Fixed::Fixed(const int num){
	_fixedPointNum = num << _fractional;
}

Fixed::Fixed(const float num) {
	_fixedPointNum = (int)(num * (1 << _fractional));
}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed &copy):_fixedPointNum(copy._fixedPointNum) {}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	_fixedPointNum = ref._fixedPointNum;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &ref)
{
	out << ref.toFloat();

	return (out);
}

bool	Fixed::operator>(const Fixed &ref)
{
	if (this->_fixedPointNum > ref._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &ref)
{
	if (this->_fixedPointNum < ref._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &ref)
{
	if (this->_fixedPointNum >= ref._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &ref)
{
	if (this->_fixedPointNum <= ref._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &ref)
{
	if (this->_fixedPointNum == ref._fixedPointNum)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &ref)
{
	if (this->_fixedPointNum != ref._fixedPointNum)
		return (true);
	return (false);
}


Fixed	Fixed::operator+(const Fixed &ref)
{
	Fixed	add(this->_fixedPointNum + ref._fixedPointNum);
	return (add);
}

Fixed	Fixed::operator-(const Fixed &ref)
{
	Fixed	add(this->_fixedPointNum - ref._fixedPointNum);
	return (add);
}

Fixed	Fixed::operator*(const Fixed &ref)
{
	Fixed	add(this->toFloat() * ref.toFloat());
	return (add);
}

Fixed	Fixed::operator/(const Fixed &ref)
{
	Fixed	add(this->_fixedPointNum / ref._fixedPointNum);
	return (add);
}

Fixed	&Fixed::operator++(void)
{
	this->_fixedPointNum++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedPointNum--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed tmp(*this);
	this->_fixedPointNum++;
	return (tmp);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed tmp(*this);
	this->_fixedPointNum--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixedPointNum > b._fixedPointNum)
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixedPointNum < b._fixedPointNum)
		return (b);
	return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (Fixed(a) > Fixed(b))
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (Fixed(a) < Fixed(b))
		return (b);
	return (a);
}

int	Fixed::getRawBits(void) const
{
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