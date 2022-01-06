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

public:
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat	&operator=(const Bureaucrat &ref);
	Bureaucrat(const std::string &name, int grade);

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

	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int value);
	void				signForm(Form &ref);
	void				incrementGrade();
	void				decrementGrade();
	void				checkException(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &ref);

#endif