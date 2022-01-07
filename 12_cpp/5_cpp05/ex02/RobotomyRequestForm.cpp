#include "RobotomyRequestForm.hpp"

std::string	const RobotomyRequestForm::st_mName = "RobotomyRequestForm";

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	Form(this->st_mName, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) :
	Form(ref), _target(ref._target) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	if (this == &ref) return (*this);

	this->_target = ref._target;
	return (*this);
}

void		RobotomyRequestForm::action(Bureaucrat const &executor) const
{
	this->execute(executor);
	std::cout << "Drrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
	if ((unsigned int)time(NULL) % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " failed to robotize" << std::endl;
}
