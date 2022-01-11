#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

class Scalar
{
public:
	Scalar(const Scalar &ref);
	Scalar(const std::string &value);
	Scalar	&operator=(const Scalar &ref);
	~Scalar(void);

	void	PrintToChar(std::ostream &out) const;
	void	PrintToInt(std::ostream &out) const;
	void	PrintToFloat(std::ostream &out) const;
	void	PrintToDouble(std::ostream &out) const;

private:
	std::string	m_value;

	class ConvertException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};

	Scalar(void);
};

std::ostream	&operator<<(std::ostream &out , const Scalar &ref);


#endif
