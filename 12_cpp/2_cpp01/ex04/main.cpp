#include "Replace.hpp"

int	main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cout << "Enter filename, s1, s2" << std::endl;
		return (1);
	}
	Replace	repl(av[1], av[2], av[3]);
	if (repl.checkEmpty())
		return (1);
	if (repl.setFilestr())
		return (errno);
	repl.replaceStr();
	if (repl.putFilestr())
		return (errno);
	return (0);
}
