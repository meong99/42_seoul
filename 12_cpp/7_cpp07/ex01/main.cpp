#include <iostream>
#include "iter.hpp"

template <typename T>
void	ft_print(const T &element)
{
	std::cout << element << std::endl;
}

int	main(void)
{
	std::string s_arr[5] = {"hello", "42", "seoul", "sohelee", "world"};
	int			i_arr[6] = {1, 2, 3, 4, 5, 6};

	std::cout << "------string------" << std::endl;
	iter(s_arr, 5, ft_print);
	std::cout << "------int------" << std::endl;
	iter(i_arr, 6, ft_print);
}