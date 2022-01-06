#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;
class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	Bureaucrat(void);

	void				checkException(void) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

public:
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat	&operator=(const Bureaucrat &ref);
	Bureaucrat(const std::string &name, int grade);

	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int value);
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &ref);
	void				executeForm(Form const & form);
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &ref);

#endif