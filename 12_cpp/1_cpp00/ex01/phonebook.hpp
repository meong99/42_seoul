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

	void	_exitPhonebook(void);
public:
	bool	is_working;

	Phonebook(void);
	~Phonebook(void);
	void	enter_command(std::string &command);
	void	run_command(const std::string command);
};

#endif
