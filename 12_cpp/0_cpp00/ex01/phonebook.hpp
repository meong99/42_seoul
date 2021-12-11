#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "add.hpp"
# include "search.hpp"

class Phonebook
{
private:
	std::string	_infos[8][5];
	Search		_search;
	Add			_add;
	int			_index;

	bool	_exitPhonebook(void);
public:
	Phonebook(void);
	~Phonebook(void);

	bool	run_command(const std::string command);
};

#endif
