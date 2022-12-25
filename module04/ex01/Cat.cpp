#include "Cat.hpp"

//==== constructors =====================================================================

Cat::Cat(void)
{
	_type = this->getClassName();
	_brain = new Brain();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	_brain = new Brain();
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type =other._type;
		delete _brain;
		_brain = new Brain();
		for (int i = 0; i < 100; i++)
			_brain->setIdea(i, other._brain->getIdea(i));
		std::cout << GREEN << "Copy assignment operator" << WHITE << " of ";
		std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Copy assignment operator" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << RED << "Destructor" << WHITE << " of " << BLUE << this->getClassName();
	std::cout << WHITE << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	Cat::makeSound() const
{
	std::cout << CYAN << "🐱 meooooooooooow..." << RESET << std::endl;
}

//==== member functions by me (for better testing)=======================================

std::string	Cat::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}

void	Cat::setBrainIdea(int index, const std::string& idea)
{
	if (index >= 0 and index < 100)
		_brain->setIdea(index, idea);
}

const std::string	&Cat::getBrainIdea(int index) const
{
	if (index >= 0 and index < 100)
		return (_brain->getIdea(index));
	const std::string &str = "";
	return (str);
}
