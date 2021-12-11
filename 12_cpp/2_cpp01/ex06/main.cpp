#include "Karen.hpp"

int	main(int ac, char **av)
{
	Karen karen;
	
	if (ac < 2)
	{
		std::cout << "Too few parameters." << std::endl;
		return (1);
	}

	karen.complain(av[1]);
}
