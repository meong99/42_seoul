#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Form
{
private:
	Form(void);
	const std::string	_name;
	const int			_forSign;
	const int			_forExecute;
	bool				_signed;
	void				checkException(void) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};

public:
	virtual ~Form(void);
	Form(const Form &ref);
	Form(const std::string &name, int forSign, int forExecute);
	Form	&operator=(const Form &ref);

	const std::string	&getName(void) const;
	int					getForSign(void) const;
	int					getForExecute(void) const;
	bool				getSigned(void) const;
	void				beSigned(const Bureaucrat &ref);
	void				execute(Bureaucrat const & executor) const;
	virtual void		action(Bureaucrat const &executer) const = 0;

	class GradeTooLowToSignException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowToExecuteException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class NotSignedException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &ref);

#endif