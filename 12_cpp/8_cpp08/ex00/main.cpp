#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "easyfind.hpp"

int	main(void)
{
	int					arr[] = {1, 2, 3, 4, 5};
	std::vector<int>	vec;
	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		vec.push_back(arr[i]);

	for (std::vector<int>::iterator	iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << *easyfind(vec, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}