#include <cmath>
#include "Convert.hpp"

Convert::Convert(void) {}

Convert::~Convert(void) {}

Convert::Convert(const Convert &ref) : m_value(ref.m_value) {}

Convert::Convert(const std::string &value) : m_value(value) {}

Convert	&Convert::operator=(const Convert &ref)
{
	if (this == &ref) return (*this);

	m_value = ref.m_value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Convert &ref)
{
	try
	{
		ref.IsImpossible();
		ref.PrintToChar(out);
		ref.PrintToInt(out);
		ref.PrintToFloat(out);
		ref.PrintToDouble(out);
	}
	catch(...)
	{
		out << "char : " << "impossible" << std::endl;
		out << "int : " << "impossible" << std::endl;
		out << "float : " << "impossible" << std::endl;
		out << "double : " << "impossible";
	}
	return (out);
}

bool	Convert::isNanInf(void) const
{
	if (!m_value.compare("nan") || !m_value.compare("nanf") ||
		!m_value.compare("inf") || !m_value.compare("inff") ||
		!m_value.compare("-inf") || !m_value.compare("-inff") ||
		!m_value.compare("+inf") || !m_value.compare("+inff"))
		return (true);
	return (false);
}

bool	Convert::isAllNumbers(void) const
{
	int		length = static_cast<int>(m_value.length());
	int		point = 0;
	bool	minus = false;

	if (m_value[0] == '-')
		minus = true;

	for (int i = 0; i < length; i++)
	{
		if (i == 0 && minus)
			i++;
		if (m_value[i] == '.')
			point++;
		if (i == length - 1 && m_value[i] == 'f')
			break ;
		if (m_value[i] != '.' && !isdigit(m_value[i]))
			return (false);
	}
	if (point > 1)
		return (false);
	return (true);
}

bool	Convert::IsImpossible(void) const
{
	if (isNanInf())
		return (false);
	if(isAllNumbers())
		return (false);
	throw ("impossible");
}

void	Convert::PrintToChar(std::ostream &out) const
{
	out << "char : ";
	try
	{
		int	to_int = std::stoi(m_value);
		if (to_int > 255 || to_int < 0)
			throw ("impossible");
		if (!isprint(to_int))
			throw ("Non displayable");
		out << '\'' << static_cast<char>(to_int) << '\'' << std::endl;
	}
	catch (const char *str)
	{
		out << str << std::endl;
	}
	catch (...)
	{
		out << "impossible" << std::endl;
	}
}

void	Convert::PrintToInt(std::ostream &out) const
{
	out << "Int : ";
	try
	{
		int	to_int = std::stoi(m_value);
		out << to_int << std::endl;
	}
	catch(...)
	{
		out << "impossible" << std::endl;
	}
}

void	Convert::PrintToFloat(std::ostream &out) const
{
	out << "Float : ";
	try
	{
		float	to_float = std::stof(m_value);
		out << to_float;
		if (!isnan(to_float) && to_float - static_cast<int>(to_float) == 0)
			out << ".0";
		out << "f" << std::endl;
	}
	catch(...)
	{
		out << "impossible" << std::endl;
	}
}

void	Convert::PrintToDouble(std::ostream &out) const
{
	out << "Double : ";
	try
	{
		double	to_double = std::stod(m_value);
		out << to_double;
		if (!isnan(to_double) && to_double - static_cast<int>(to_double) == 0)
			out << ".0";
	}
	catch(...)
	{
		out << "impossible";
	}
}
