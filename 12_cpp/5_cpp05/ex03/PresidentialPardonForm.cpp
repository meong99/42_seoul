#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::st_mName = "PresidentialPardonForm";

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	Form(this->st_mName, 72, 45), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) :
	Form(ref), _target(ref._target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this == &ref) return (*this);
	
	this->_target = ref._target;
	return (*this);
}

void		PresidentialPardonForm::action(Bureaucrat const &executor) const
{
	this->execute(executor);
	std::cout << this->_target << "has been pardoned by Zafod Beeblebrox." << std::endl;
}

Form	*PresidentialPardonForm::create(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}