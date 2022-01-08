#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Bread", 100);
		std::cout << bureaucrat << std::endl << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl << std::endl;

		bureaucrat.setGrade(30);
		std::cout << bureaucrat << std::endl << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl << std::endl;

		//예외 발생
		// Bureaucrat	bureaucrat("Bread", 1000);
		// bureaucrat.setGrade(-123);

		// bureaucrat.setGrade(500);
		
		// bureaucrat.setGrade(1);
		// bureaucrat.incrementGrade();

		// bureaucrat.setGrade(150);
		// bureaucrat.decrementGrade();
		std::cout << std::endl;
		{
			Form	form("first", 42, 42);
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
		}
		std::cout << std::endl;
		{
			Form	form("first", 20, 50);
			bureaucrat.signForm(form);
		}
		// 예외 발생

		// std::cout << std::endl;
		// Form	form("first", 160, 42);
		// Form	form("first", 42, 160);
		// Form	form("first", -1, 42);
		// Form	form("first", 42, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}