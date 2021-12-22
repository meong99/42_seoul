#include <iostream>

void print(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << (char)std::toupper(str[i]);
	std::cout << std::endl;
}

int main(int ac, const char **av)
{
	std::string	str;

	if (ac == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
		str += av[i];
	print(str);
	
	return (0);
}