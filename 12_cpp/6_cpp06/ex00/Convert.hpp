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

	void	PrintToChar(std::ostream &out) const;
	void	PrintToInt(std::ostream &out) const;
	void	PrintToFloat(std::ostream &out) const;
	void	PrintToDouble(std::ostream &out) const;

private:
	Convert(void);

	std::string	m_str;
	double		m_value;
	char		m_char;
};

std::ostream	&operator<<(std::ostream &out , const Convert &ref);


#endif
