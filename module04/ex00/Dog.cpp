#include "Dog.hpp"

//==== constructors =====================================================================

Dog::Dog(void)
{
	_type = this->getClassName();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
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
