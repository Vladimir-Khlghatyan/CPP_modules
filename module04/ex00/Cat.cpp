#include "Cat.hpp"

//==== constructors =====================================================================

Cat::Cat(void)
{
	_type = this->getClassName();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type =other._type;
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
