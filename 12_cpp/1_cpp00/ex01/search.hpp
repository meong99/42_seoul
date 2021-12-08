#ifndef SEARCH_HPP
# define SEARCH_HPP

# include "color.h"
# include <iostream>
# include <iomanip>

class Search
{
private	:
	void	_print_list(std::string str[], std::string color, int index);
	void	_print_info(std::string (&_infos)[8][5], int index);
public	:
	void	search(std::string (&_infos)[8][5], int _index);
};
#endif