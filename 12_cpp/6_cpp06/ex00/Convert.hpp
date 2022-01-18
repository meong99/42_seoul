#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

class Convert
{
public:
	Convert(const Convert &ref);
	Convert(const std::string &value);
	Convert	&operator=(const Convert &ref);
	~Convert(void);

	bool	IsImpossible(void) const;
	void	PrintToChar(std::ostream &out) const;
	void	PrintToInt(std::ostream &out) const;
	void	PrintToFloat(std::ostream &out) const;
	void	PrintToDouble(std::ostream &out) const;

private:
	Convert(void);

	std::string	m_value;

	bool	isChar(void) const;
	bool	isNanInf(void) const;
	bool	isAllNumbers(void) const;
};

std::ostream	&operator<<(std::ostream &out , const Convert &ref);


#endif
