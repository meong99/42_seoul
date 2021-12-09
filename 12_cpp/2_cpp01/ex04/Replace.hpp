#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
private:
	std::string	_filename;
	std::string	_filestr;
	std::string	_s1;
	std::string	_s2;

public:
	Replace( void );
	Replace( std::string filename, std::string s1, std::string s2 );
	~Replace( void );

	bool	checkEmpty( void );
	int		setFilestr(void);
	void	replaceStr(void);
	int		putFilestr(void);
};


#endif
