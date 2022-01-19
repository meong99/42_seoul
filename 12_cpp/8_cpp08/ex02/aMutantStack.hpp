#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void);
	MutantStack(const MutantStack<T, Container>& copy);
	~MutantStack(void);
	MutantStack<T, Container>&	operator=(const MutantStack<T, Container>& copy);

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator				begin(void);
	iterator				end(void);
	const_iterator			cbegin(void);
	const_iterator			cend(void);
	reverse_iterator		rbegin(void);
	reverse_iterator		rend(void);
	const_reverse_iterator	crbegin(void);
	const_reverse_iterator	crend(void);
};

#endif
