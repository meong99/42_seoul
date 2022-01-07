#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &ref);

	virtual void		action(Bureaucrat const &executor) const;
	static Form			*create(const std::string &target);

private:
	std::string					_target;
	static const std::string	st_mName;

	RobotomyRequestForm(void);
};

#endif