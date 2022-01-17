#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>

class span
{
private:
	span(void);
	unsigned int		m_size;
	std::vector<int>	m_saved;
public:
	span(const span& copy);
	span(unsigned int N);
	~span(void);
	span&	operator=(const span& copy);

	void			addNumber(int num);
	void			setSize(unsigned int size);
	unsigned int	getSize(void) const;
};

#endif
