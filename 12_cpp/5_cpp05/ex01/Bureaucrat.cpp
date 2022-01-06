#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat &ref):_name(ref._name), _grade(ref._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade):_name(name), _grade(grade)
{
	this->checkException();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this == &ref) return (*this);

	this->_grade = ref._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &ref)
{
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade();

	return (out);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int value)
{
	this->_grade = value;
	this->checkException();
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	this->checkException();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	this->checkException();
}

void	Bureaucrat::signForm(Form &ref)
{
	try
	{
		if (this->_grade > ref.getForExecute())
			throw (Form::GradeTooLowToExecute());
		ref.beSigned(*this);
		std::cout << this->_name << " signs " << ref.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " cannot sign " << ref.getName() << " because " << this->_name << "'s "<< e.what() << std::endl;
	}
}

void	Bureaucrat::checkException(void) const
{
	if (this->_grade > 150) throw (Bureaucrat::GradeTooLowException());
	if (this->_grade < 1) throw (Bureaucrat::GradeTooHighException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The maximum value of grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The minimum value of grade is 150");
}
