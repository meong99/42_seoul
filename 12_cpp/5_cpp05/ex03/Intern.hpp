#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class Form;

class Intern
{
public:
	Intern(void);
	~Intern(void);

	Form	*makeForm(const std::string &formsName, const std::string &formsTarget);

private:
	Intern(const Intern &ref);
	Intern	&operator=(const Intern &ref);
};

#endif