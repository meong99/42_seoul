#include "Form.hpp"
# include "Bureaucrat.hpp"

Form::~Form(void) {}

Form::Form(const Form &ref):_name(ref._name), _forSign(ref._forSign), _forExecute(ref._forExecute), _signed(ref._signed) {}

Form::Form(const std::string &name, int forSign, int forExecute):_name(name), _forSign(forSign), _forExecute(forExecute), _signed(false)
{
	this->checkException();
}

Form	&Form::operator=(const Form &ref)
{
	this->_signed = ref._signed;
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

int	Form::getForSign(void) const
{
	return (this->_forSign);
}

int	Form::getForExecute(void) const
{
	return (this->_forExecute);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

void	Form::beSigned(const Bureaucrat &ref)
{
	if (ref.getGrade() > this->_forSign)
		throw (Form::GradeTooLowToSignException());
	this->_signed = true;
}

void	Form::checkException(void) const
{
	if (this->_forSign < 1 || this->_forExecute < 1) throw (Form::GradeTooHighException());
	if (this->_forSign > 150 || this->_forExecute > 150) throw (Form::GradeTooLowException());
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("It's too high. The range of grades is 1 to 150.");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("It's too low. The range of grades is 1 to 150.");
}

const char	*Form::GradeTooLowToSignException::what(void) const throw()
{
	return ("grade is too low to sign");
}

const char	*Form::GradeTooLowToExecuteException::what(void) const throw()
{
	return ("grade is too low to execute");
}

std::ostream	&operator<<(std::ostream &out, const Form &ref)
{
	out << "name : " << ref.getName() << "\nSign : " << ref.getForSign() << "\nexecute : " << ref.getForExecute() << "\n";
	if (ref.getSigned())
		out << "Form is signed";
	else
		out << "Form is not signed";
	return (out);
}
