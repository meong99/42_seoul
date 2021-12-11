#include "Karen.hpp"

int	main(void)
{
	Karen karen;

	std::cout << "DEBUG" << std::endl;
	karen.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO" << std::endl;
	karen.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING" << std::endl;
	karen.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR" << std::endl;
	karen.complain("ERROR");
	std::cout << std::endl;
}
