#include "Brain.hpp"

//==== constructors =====================================================================

Brain::Brain(void) : _noIdea("")
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Brain::Brain(const Brain &other) : _noIdea("")
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
		std::cout << GREEN << "Copy assignment operator" << WHITE << " of ";
		std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Copy assignment operator" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << RED << "Destructor" << WHITE << " of " << BLUE << this->getClassName();
	std::cout << WHITE << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

//==== member functions by me (for better testing)=======================================

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 and index < 100)
		_ideas[index] = idea;
}

const std::string	&Brain::getIdea(int index) const
{
	if (index >= 0 and index < 100)
		return (_ideas[index]);
	return (_noIdea);
}

std::string	Brain::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}
