#include <cmath>
#include "Convert.hpp"

Convert::Convert(void) {}

Convert::~Convert(void) {}

Convert::Convert(const Convert &ref) : m_str(ref.m_str), m_value(ref.m_value), m_char(ref.m_char) {}

Convert::Convert(const std::string &value) : m_str(value), m_value(atof(value.c_str()))
{
	if (value.length() == 1 && !(value[0] >= '0' && value[0] <= '9'))
		m_char = value[0];
	else
		m_char = -1;
}

Convert	&Convert::operator=(const Convert &ref)
{
	if (this == &ref) return (*this);

	m_str = ref.m_str;
	m_value = ref.m_value;
	m_char = ref.m_char;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Convert &ref)
{
	ref.PrintToChar(out);
	ref.PrintToInt(out);
	ref.PrintToFloat(out);
	ref.PrintToDouble(out);
	return (out);
}

void	Convert::PrintToChar(std::ostream &out) const
{
	out << "char : ";
	try
	{
		if (m_char == -1 && (isnan(m_value) || m_value > CHAR_MAX || m_value < CHAR_MIN ||
			(m_value == 0 && m_str[0] != '0')))
			throw ("impossible");

		char	to_char;
		to_char = static_cast<char>(m_value);
		if (m_char != -1)
			to_char = m_char;
		if (!isprint(to_char))
			throw ("Non displayable");
		out << '\'' << to_char << '\'' << std::endl;
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
		if (isnan(m_value) || m_value > INT_MAX || m_value < INT_MIN ||
			(m_value == 0 && m_str[0] != '0'))
			throw ("impossible");

		int	to_int = static_cast<int>(m_value);
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
		float	to_float = static_cast<float>(m_value);
		if ((!isinf(to_float) && !isnan(to_float) && (m_value > __FLT_MAX__ || m_value < -__FLT_MAX__)) || 
			(m_value == 0 && m_str[0] != '0'))
			throw ("impossible");
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
		if (m_value == 0 && m_str[0] != '0')
			throw ("impossible");
		out << m_value;
		if (!isnan(m_value) && m_value - static_cast<int>(m_value) == 0)
			out << ".0";
	}
	catch(...)
	{
		out << "impossible";
	}
}
