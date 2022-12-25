#include "Dog.hpp"

//==== constructors =====================================================================

Dog::Dog(void)
{
	_type = this->getClassName();
	_brain = new Brain();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	_brain = new Brain();
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
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

Dog::~Dog(void)
{
	delete _brain;
	std::cout << RED << "Destructor" << WHITE << " of " << BLUE << this->getClassName();
	std::cout << WHITE << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	Dog::makeSound() const
{
	std::cout << BLUE << "🐶 woof woof woof..." << RESET << std::endl;
}

//==== member functions by me (for better testing)=======================================

std::string	Dog::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}

void	Dog::setBrainIdea(int index, const std::string& idea)
{
	if (index >= 0 and index < 100)
		_brain->setIdea(index, idea);
}

const std::string	&Dog::getBrainIdea(int index) const
{
	if (index >= 0 and index < 100)
		return (_brain->getIdea(index));
	const std::string &str = "";
	return (str);
}
