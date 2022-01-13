#ifndef SEARCH_HPP
# define SEARCH_HPP

# include "color.h"
# include <iostream>
# include <iomanip>

#include "Contact.hpp"

class Search
{
private	:
	void	_print_list(std::string str[], std::string color, int index);
public	:
	void	search(Contact &contect, int _index);
};
#endif