#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Form	*Intern::makeForm(const std::string &formsName, const std::string &formsTarget)
{
	std::string	nameArr[3] = {
		PresidentialPardonForm(formsTarget).getName(),
		RobotomyRequestForm(formsTarget).getName(),
		ShrubberyCreationForm(formsTarget).getName(),
	};
	Form	*(*ptrArr[3])(const std::string &target) = {
		&PresidentialPardonForm::create,
		&RobotomyRequestForm::create,
		&ShrubberyCreationForm::create
	};

	for (int i = 0; i < 3; i++)
	{
		if (nameArr[i] == formsName)
		{
			std::cout << "Intern creates " << nameArr[i] << std::endl;
			return ((*ptrArr[i])(formsTarget));
		}
	}
	std::cout << "The requested form could not be found" << std::endl;
	return (nullptr);
}