#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& copy) : std::stack<T, Container>(copy) {}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

template <typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack& copy)
{
	if (this == &copy) return (*this);

	this->stack::operator=(copy);
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::cbegin(void)
{
	return (this->c.cbegin());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::cend(void)
{
	return (this->c.cend());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::crbegin(void)
{
	return (this->c.crbegin());
}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::crend(void)
{
	return (this->c.crend());
}