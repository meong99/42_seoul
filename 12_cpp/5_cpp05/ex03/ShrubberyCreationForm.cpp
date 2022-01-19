#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::st_mName = "ShrubberyCreationForm";

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	Form(st_mName, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) :
	Form(ref), _target(ref._target) {}


ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	if (this == &ref) return (*this);
	
	this->_target = ref._target;
	return (*this);
}

void	ShrubberyCreationForm::action(Bureaucrat const &executor) const
{
	this->execute(executor);
	std::ofstream outStream(this->_target + "_shrubbery");
	if (outStream.is_open() == false)
		throw (std::ofstream::failure("Fialed to open " + this->_target + "_shrubbery"));
	outStream << ASCII_TREE;
	std::cout << executor.getName() << "create ascii tree" << std::endl;
}
Form		*ShrubberyCreationForm::create(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
