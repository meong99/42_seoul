#include "Scalar.hpp"

Scalar::Scalar(void) {}

Scalar::~Scalar(void) {}

Scalar::Scalar(const Scalar &ref) : m_value(ref.m_value){}

Scalar::Scalar(const std::string &value) : m_value(value) {}

Scalar	&Scalar::operator=(const Scalar &ref)
{
	if (this == &ref) return (*this);

	this->m_value = ref.m_value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Scalar &ref)
{
	ref.PrintToChar(out);
	ref.PrintToInt(out);
	ref.PrintToFloat(out);
	ref.PrintToDouble(out);

	return (out);
}

void	Scalar::PrintToChar(std::ostream &out) const
{
	char	cValue = this->m_value[0];

	out << "char : ";
	try
	{
		int	length = static_cast<int>(this->m_value.length());
		if (length != 1)
			throw (Scalar::ConvertException());
		if (static_cast<int>(cValue) >= 127 || static_cast<int>(cValue) <= 31)
			throw ("Non displayable");

		out << cValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const char *str)
	{
		std::cerr << str << std::endl;
	}
}

void	Scalar::PrintToInt(std::ostream &out) const
{
	out << "Int : ";
	try
	{
		int	length = static_cast<int>(this->m_value.length());
		if (length == 0)
			throw (Scalar::ConvertException());
		for (int i = length - 1; i >= 0; i--)
		{
			if (length > 1 && i == 0 && this->m_value[i] == '-')
				break ;
			if (!std::isdigit(this->m_value[i]))
			{
				throw (Scalar::ConvertException());
			}
		}
		int	iValue = std::stoi(this->m_value);
		out << iValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Scalar::PrintToFloat(std::ostream &out) const
{
	out << "Float : ";
	try
	{
		int	length = static_cast<int>(this->m_value.length());
		if (length == 0)
			throw (Scalar::ConvertException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Scalar::PrintToDouble(std::ostream &out) const
{
	out << "Double : ";
}

const char	*Scalar::ConvertException::what(void) const throw()
{
	return ("impossible");
}
