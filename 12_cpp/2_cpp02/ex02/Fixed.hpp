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
	Fixed(int num);
	Fixed(float num);
	~Fixed(void);
	Fixed(const Fixed &copy);

	Fixed	&operator=(const Fixed &ref);

	bool	operator>(const Fixed &ref) const;
	bool	operator<(const Fixed &ref) const;
	bool	operator>=(const Fixed &ref) const;
	bool	operator<=(const Fixed &ref) const;
	bool	operator==(const Fixed &ref) const;
	bool	operator!=(const Fixed &ref) const;

	Fixed	operator+(const Fixed &ref) const;
	Fixed	operator-(const Fixed &ref) const;
	Fixed	operator*(const Fixed &ref) const;
	Fixed	operator/(const Fixed &ref) const;

	Fixed			&operator++(void);
	Fixed			&operator--(void);
	const Fixed		operator++(int);
	const Fixed		operator--(int);

	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &ref);


#endif