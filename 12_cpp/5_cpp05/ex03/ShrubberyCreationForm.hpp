#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &ref);

	virtual void		action(Bureaucrat const &executor) const;
	static Form			*create(const std::string &target);

private:
	std::string					_target;
	static const std::string	st_mName;

	ShrubberyCreationForm(void);
};

# define ASCII_TREE "\n\
    ,~    \n\
    ==    \n\
    *=    \n\
    =~    \n\
   ;=*~   \n\
   ==*=   \n\
   *=$~   \n\
   !$-=   \n\
   ====   \n\
"

#endif