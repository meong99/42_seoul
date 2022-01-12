#include <time.h>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	switch ((unsigned int)time(NULL) % 3)
	{
	case 0:
		std::cout << "creat A" << std::endl;
		return (new A());
		break;
	case 1:
		std::cout << "creat B" << std::endl;
		return (new B());
		break;
	default:
		std::cout << "creat C" << std::endl;
		return (new C());
		break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	dyn_a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(...)
	{
		try
		{
			B	dyn_b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{
			std::cout << "C" << std::endl;
		}
	}
}

int	main(void)
{
	Base	*base = generate();
	identify(base);
	identify(*base);
	return (0);
}