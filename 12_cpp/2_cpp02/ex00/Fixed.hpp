#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_fixedPointNum;
	static const int	_fractional;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &copy);
	Fixed	&operator=(const Fixed &ref);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif