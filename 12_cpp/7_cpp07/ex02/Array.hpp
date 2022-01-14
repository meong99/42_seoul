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
	Array(void)
	{
		m_n = 0;
		numbers = new T[0];
	};
	Array(unsigned int n)
	{
		m_n = n;
		numbers = new T[m_n];
	};
	Array(const Array &ref)
	{
		m_n = ref.size();
		numbers = new T[m_n];
		for (int i = 0; i < m_n; i++)
			numbers[i] = ref.numbers[i];
	};
	~Array(void)
	{
		delete []numbers;
	};
	Array	&operator=(const Array &ref)
	{
		if (this == &ref) return (*this);
		delete []numbers;
		m_n = ref.size();
		numbers = new T[m_n];
		for (int i = 0; i < ref.m_n; i++)
		{
			numbers[i] = ref.numbers[i];
		}
		return (*this);
	};
	T		&operator[](int index)
	{
		if (index < 0 || index >= m_n)
			throw (Array::OutOfRange());
		return (numbers[index]);
	};

	int		size(void) const
	{
		return (m_n);
	};

	T	*getArray(void)
	{
		return (numbers);
	};

	class OutOfRange : public std::exception
	{
		virtual const char *what() const throw ()
		{
			return ("Out of range");
		}
	};
};

#endif