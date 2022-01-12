#include "Convert.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Put in one parameter" << std::endl;
		return (1);
	}

	Convert	convert(argv[1]);

	std::cout << convert << std::endl;
}