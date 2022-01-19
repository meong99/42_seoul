#include <iostream>
#include <list>
#include <string>
#include "MutantStack.cpp"

void test_list(void)
{
	std::cout << std::endl << "===test_list()===" << std::endl;
	MutantStack<int, std::list<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int, std::list<int> >::iterator it = mstack.begin();
	MutantStack<int, std::list<int> >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int> > s(mstack);
}

void test_reverse_it(void)
{
	std::cout << std::endl << "===test_reverse_it()===" << std::endl;
	MutantStack<std::string> mstack;
	mstack.push("one");
	mstack.push("two");
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push("three");
	mstack.push("four");
	mstack.push("five");
	mstack.push("six");
	MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
	MutantStack<std::string>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack<std::string> s(mstack);
}

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	test_list();
	test_reverse_it();
	return 0;
}