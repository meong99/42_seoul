#ifndef EASTFIND_HPP
# define EASTFIND_HPP

class	NotFoundException : public std::exception
{
	virtual const char *what(void) const throw()
	{
		return ("Not found");
	}
};

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw (NotFoundException());
	return (iter);
}

#endif