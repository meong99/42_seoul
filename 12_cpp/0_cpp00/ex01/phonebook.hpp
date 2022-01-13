#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Add.hpp"
# include "Search.hpp"
# include "Contact.hpp"

class Phonebook
{
private:
	Contact		_contact;
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
