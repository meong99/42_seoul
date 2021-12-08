#include <iostream>

class Megaphone
{
private:
	std::string _putstr;

public:
	void print(void);
	void add_str(std::string str);
};

void Megaphone::print(void)
{
	for (size_t i = 0; i < _putstr.length(); i++)
		std::cout << (char)std::toupper(_putstr[i]);
	std::cout << std::endl;
}

void Megaphone::add_str(std::string str)
{
	_putstr += str;
}

int main(int ac, const char **av)
{
	Megaphone megaphone;

	if (ac == 1)
		megaphone.add_str("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	for (int i = 1; i < ac; i++)
		megaphone.add_str(av[i]);
	megaphone.print();
	return (0);
}