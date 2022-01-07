#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &ref);
	~PresidentialPardonForm(void);
	
	virtual void		action(Bureaucrat const &executor) const;
	static Form			*create(const std::string &target);

private:
	std::string					_target;
	static const std::string	st_mName;

	PresidentialPardonForm(void);
};

#endif