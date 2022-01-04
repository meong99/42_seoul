#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat &ref):_name(ref._name), _grade(ref._grade) 
{
	if (this->_grade > 150) throw (Bureaucrat::GradeTooLowException());
	if (this->_grade < 1) throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this == &ref) return (*this);

	this->_grade = ref._grade;
	if (this->_grade > 150) throw (Bureaucrat::GradeTooLowException());
	if (this->_grade < 1) throw (Bureaucrat::GradeTooHighException());

	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):_name(name), _grade(grade)
{
	if (this->_grade > 150) throw (Bureaucrat::GradeTooLowException());
	if (this->_grade < 1) throw (Bureaucrat::GradeTooHighException());
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int value)
{
	this->_grade = value;
	if (this->_grade > 150) throw (Bureaucrat::GradeTooLowException());
	if (this->_grade < 1) throw (Bureaucrat::GradeTooHighException());
}


void	Bureaucrat::incrementGrade(void) throw(Bureaucrat::GradeTooHighException)
{
	this->_grade--;
	if (_grade < 1) throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::decrementGrade(void) throw(Bureaucrat::GradeTooLowException)
{
	this->_grade++;
	if (_grade > 150) throw (Bureaucrat::GradeTooLowException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The maximum value of grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The minimum value of grade is 150");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;

	return (out);
}