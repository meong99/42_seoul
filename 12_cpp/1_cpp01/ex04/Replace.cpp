#include "Replace.hpp"

Replace::Replace( void ) {}

Replace::Replace( std::string filename, std::string s1, std::string s2 ):
	_filename(filename), _filestr(""), _s1(s1), _s2(s2) {}

Replace::~Replace( void ) {}

bool	Replace::checkEmpty( void )
{
	if (_filename.empty() || _s1.empty() || _s2.empty())
	{
		std::cerr << "filename, s1 and s2 should not be empty." << std::endl;
		return (true);
	}
	return (false);
}

int	Replace::setFilestr(void)
{
	std::ifstream	in(_filename);
	
	if (in.fail())
	{
		std::cerr << strerror( errno ) << std::endl;
		return ( errno );
	}

	in.seekg( 0, std::ios::end );
	size_t size = in.tellg();
	_filestr.resize( size );
	in.seekg( 0, std::ios::beg );
	in.read( &_filestr[0], size );
	in.close();

	return (0);
}

void	Replace::replaceStr(void)
{
	std::string::size_type offset = 0;

	while (true)
	{
		offset = _filestr.find(_s1, offset);
		if ( offset == std::string::npos )
			break ;
		else
		{
			_filestr.erase(offset, _s1.length());
			_filestr.insert(offset, _s2);
		}
	}
}

int	Replace::putFilestr(void)
{
	std::ofstream	out(_filename + ".replace");

	if (out.fail())
	{
		std::cerr << strerror( errno ) << std::endl;
		return ( errno );
	}
	out << _filestr;

	return (0);
}
