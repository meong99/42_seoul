#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_fixedPointNum;
	static const int	_fractional = 8;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(int num);
	Fixed(float num);
	Fixed(const Fixed &copy);
	Fixed	&operator=(const Fixed &ref);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &ref);

#endif