#ifndef SPAN_HPP
#define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
private:
	Span(void);
	unsigned int		_size;
	std::vector<int>	_vec;

public:
	Span(const Span& copy);
	Span(unsigned int N);
	~Span(void);
	Span&	operator=(const Span& copy);

	void					setSize(unsigned int size);
	unsigned int			getSize(void) const;
	const std::vector<int>	&getVector(void) const;

	void	addNumber(int num);
	template <typename T>
	void	addNumber(const T &begin, const T &end)
	{
		if (std::distance(begin, end) + _vec.size() > _size)
			throw (FullException());
		_vec.insert(_vec.begin() + _vec.size(), begin, end);
	}
	long	shortestSpan(void);
	long	longestSpan(void);

	class	FullException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class	NotenoughException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
};

#endif
