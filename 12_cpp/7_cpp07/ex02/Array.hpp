#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T	*numbers;
	int	m_n;

public:
	Array(void) : m_n(0)
	{
	};
	Array(unsigned int n)
	{
		m_n = n;
		new numbers[m_n];
	};
	Array(const Array &ref)
	{
		m_n = ref.m_n;
		new numbers[m_n];
	};
	~Array(void)
	{
		delete []numbers;
	};
	Array	&operator=(const Array &ref)
	{
		for (int i = 0; i < ref.m_n; i++)
		{
			numbers[i] = ref.numbers[i];
		}
		return (*this);
	};
	T		&operator[](int index)
	{
		return (numbers[i]);
	};

	int		size(void) const;
};

#endif