#include <iostream>

class	Megaphone
{
private	:
	std::string	putstr;

public	:
	void	print(void);
	void	add_str(std::string str);
};

void	Megaphone::print(void)
{
	std::cout << putstr << "\n";
}

void	Megaphone::add_str(std::string str)
{
	putstr += str;
}

int	main(int ac, const char **av)
{
	Megaphone	megaphone;
	
	if (ac == 1)
		megaphone.add_str("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	for (int i = 1; i < ac; i++)
		megaphone.add_str(av[i]);
	megaphone.print();
	return (0);
}