#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(const T *arr, int len, void(*f)(const T &))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

#endif