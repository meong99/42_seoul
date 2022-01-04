#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Bread", 100);
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.setGrade(30);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		//예외 발생
		// bureaucrat.setGrade(-123);

		// bureaucrat.setGrade(500);
		
		// bureaucrat.setGrade(1);
		// bureaucrat.incrementGrade();

		// bureaucrat.setGrade(150);
		// bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}