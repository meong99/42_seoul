#include "Brain.hpp"

Brain::Brain(void)
{
	std::string tmpIdeas[6] = {"😄", "😝", "🥰", "😞", "😭", "😕"};

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = tmpIdeas[rand() % 6];
	std::cout << "NULL_Type brain has been created!" << std::endl;
}

Brain::~Brain(void)
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = "";
	std::cout << "Bye my brain...." << std::endl;
}

Brain::Brain(const Brain &ref)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ref._ideas[i];
}

Brain	&Brain::operator=(const Brain &ref)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ref._ideas[i];
	return (*this);
}

Brain::Brain(const std::string &type)
{
	std::string tmpIdeas[6] = {"😄", "😝", "🥰", "😞", "😭", "😕"};

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = tmpIdeas[rand() % 6];
	std::cout << type << "s brain has been created!" << std::endl;
}

const std::string	Brain::getIdea(int index) const
{
	return (this->_ideas[index]);
}