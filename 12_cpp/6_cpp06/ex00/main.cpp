#include "Scalar.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "You have to pass only one parameter" << std::endl;
		return (1);
	}

	Scalar	scal(argv[1]);

	std::cout << scal << std::endl;
}