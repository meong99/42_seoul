#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T				*m_arr;
	unsigned int	m_n;

public:
	Array(void)
	{
		m_n = 0;
		m_arr = new T[m_n];
	};
	Array(unsigned int n)
	{
		m_n = n;
		m_arr = new T[m_n];
	};
	Array(const Array &ref)
	{
		m_n = ref.size();
		m_arr = new T[m_n];
		for (unsigned int i = 0; i < m_n; i++)
			m_arr[i] = ref.m_arr[i];
	};
	~Array(void)
	{
		delete []m_arr;
	};
	Array	&operator=(const Array &ref)
	{
		if (this == &ref) return (*this);
		delete []m_arr;
		m_n = ref.size();
		m_arr = new T[m_n];
		for (unsigned int i = 0; i < ref.m_n; i++)
		{
			m_arr[i] = ref.m_arr[i];
		}
		return (*this);
	};
	T		&operator[](int index)
	{
		if (index < 0 || index >= static_cast<int>(m_n))
			throw (Array::OutOfRange());
		return (m_arr[index]);
	};

	unsigned int	size(void) const
	{
		return (m_n);
	};

	T	*getArray(void)
	{
		return (m_arr);
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