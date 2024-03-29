#include "Span.hpp"

Span::Span(void) {}
Span::Span(const Span& copy)
{
	*this = copy;
}
Span::Span(unsigned int N)
{
	_size = N;
}
Span::~Span(void) {}
Span&	Span::operator=(const Span& copy)
{
	if (this == &copy) return (*this);

	_size = copy.getSize();
	_vec.clear();
	_vec = copy.getVector();
	
	return (*this);
}

void	Span::setSize(unsigned int size)
{
	_size = size;
}

unsigned int	Span::getSize(void) const
{
	return (_size);
}

const std::vector<int>	&Span::getVector(void) const
{
	return (_vec);
}

void	Span::addNumber(int	num)
{
	if (_vec.size() >= _size)
		throw (Span::FullException());
	_vec.push_back(num);
}

long	Span::shortestSpan(void)
{
	if (_vec.size() < 2)
		throw (Span::NotenoughException());
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator	first = tmp.begin();
	std::vector<int>::iterator	next = ++tmp.begin();

	long	shortest = static_cast<long>(*next) - *first;
	while (next != tmp.end())
	{
		if (static_cast<long>(*next) - *first < shortest)
			shortest = static_cast<long>(*next) - *first;
		++first;
		++next;
	}
	return (shortest);
}

long	Span::longestSpan(void)
{
	if (_vec.size() < 2)
		throw (Span::NotenoughException());
	long	longest = static_cast<long>(*std::max_element(_vec.begin(), _vec.end())) -
					*std::min_element(_vec.begin(), _vec.end());
	return (longest);
}

const char	*Span::FullException::what(void) const throw()
{
	return ("Buffer is full");
}

const char	*Span::NotenoughException::what(void) const throw()
{
	return ("Not enough buffer");
}
