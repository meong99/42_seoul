#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bobo("bobo", 22);
		Form 		*pForm;

		pForm = new PresidentialPardonForm("elen");
		pForm->beSigned(bobo);
		pForm->action(bobo);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}