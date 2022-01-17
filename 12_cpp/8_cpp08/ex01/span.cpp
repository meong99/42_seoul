#include "span.hpp"

span::span(void) {}
span::span(const span& copy)
{
	*this = copy;
}
span::span(unsigned int N)
{
	this->setSize(N);
}
span::~span(void) {}
span&	span::operator=(const span& copy)
{
	if (this == &copy) return (*this);
	this->setSize(copy.getSize());

	return (*this);
}