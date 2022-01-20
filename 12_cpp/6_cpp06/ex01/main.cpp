#include "Serialize.hpp"

int	main(void)
{
	t_Data	a;

	a.name = "sohelee";
	a.hobby = "game";

	t_Data	*b = deserialize(serialize(&a));

	std::cout << b->name << std::endl;
	std::cout << b->hobby << std::endl;
}