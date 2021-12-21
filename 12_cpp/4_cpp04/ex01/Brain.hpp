#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string _ideas[100];
	
public:
	Brain(void);
	~Brain(void);
	Brain(const std::string &type);
	Brain(const Brain &ref);
	Brain	&operator=(const Brain &ref);

	const std::string	getIdea(int index) const;
};

#endif