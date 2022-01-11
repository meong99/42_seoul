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
	ref.printToChar(out);
	ref.printToInt(out);
	ref.printToFloat(out);
	ref.printToDouble(out);

	return (out);
}

void	Scalar::printToChar(std::ostream &out) const
{
	out << "char : ";
	try
	{
		if (this->m_value.length() > 1 || this->m_value.length() < 1)
			throw (Scalar::ConvertException());

		int iValue = std::stoi(this->m_value);
		if (iValue >= 127 || iValue <= 31)
			throw ("Non displayable");

		out << static_cast<char>(iValue) << std::endl;
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

void	Scalar::printToInt(std::ostream &out) const
{
	out << "Int : ";
	try
	{
		for (int i = 0; i < this->m_value.length(); i++)
		{
			if (!std::isdigit(this->m_value[i]))
				throw (Scalar::ConvertException());
		}
		int	iValue = std::stoi(this->m_value);
		out << iValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Scalar::printToFloat(std::ostream &out) const
{
	out << "Float : ";
	try
	{
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

const char	*Scalar::ConvertException::what(void) const throw()
{
	return ("impossible");
}