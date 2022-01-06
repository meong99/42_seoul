#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_forSign;
	const int			_forExecute;
	bool				_signed;
	Form(void);

public:
	~Form(void);
	Form(const Form &ref);
	Form(const std::string &name, int forSign, int forExecute);
	Form	&operator=(const Form &ref);

	const std::string	&getName(void) const;
	int					getForSign(void) const;
	int					getForExecute(void) const;
	bool				getSigned(void) const;
	void				beSigned(const Bureaucrat &ref);
	void				checkException(void) const;
	
	class GradeTooHighException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowToSign : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowToExecute : public std::exception
	{
		virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &ref);

#endif