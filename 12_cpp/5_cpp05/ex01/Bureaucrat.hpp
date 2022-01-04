#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
	const int			&getGrade(void) const;
	void				setGrade(int value);
	void				incrementGrade() throw(Bureaucrat::GradeTooHighException);
	void				decrementGrade() throw(Bureaucrat::GradeTooLowException);
	
	
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &ref);

#endif