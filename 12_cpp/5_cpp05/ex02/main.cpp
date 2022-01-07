#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Form 		*pForm;

	try
	{
		{
			Bureaucrat	bobo("bobo", 40);

			pForm = new PresidentialPardonForm("elen");
			bobo.signForm(*pForm);
			bobo.setGrade(20);
			bobo.signForm(*pForm);
			bobo.executeForm(*pForm);
			bobo.setGrade(5);
			bobo.executeForm(*pForm);
			delete pForm;
		}
		std::cout << std::endl;
		{
			Bureaucrat	rosa("rosa", 80);
			pForm = new RobotomyRequestForm("roy");
			rosa.signForm(*pForm);
			rosa.setGrade(50);
			rosa.signForm(*pForm);
			rosa.executeForm(*pForm);
			rosa.setGrade(30);
			rosa.executeForm(*pForm);
			delete	pForm;
		}
		std::cout << std::endl;
		{
			Bureaucrat	elsa("elsa", 150);
			pForm = new ShrubberyCreationForm("anna");
			elsa.signForm(*pForm);
			elsa.setGrade(140);
			elsa.signForm(*pForm);
			elsa.executeForm(*pForm);
			elsa.setGrade(130);
			elsa.executeForm(*pForm);
			delete	pForm;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}