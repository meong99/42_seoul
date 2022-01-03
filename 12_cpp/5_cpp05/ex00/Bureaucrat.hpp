#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat	&operator=(const Bureaucrat &ref);

	const std::string	&getName() const;
	const int			&getGrade() const;
	void				incrementGrade(const int &grade);
	void				decrementGrade(const int &grade);
	
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("The maximum value of grade is 1");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("The minimum value of grade is 1.");
		}
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &ref);

#endif