#include "WrongAAnimal.hpp"

//==== constructors =====================================================================

WrongAAnimal::WrongAAnimal(void)
{
	this->_type = this->getClassName();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &other)
{
	this->_type = other._type;
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

WrongAAnimal &WrongAAnimal::operator=(const WrongAAnimal &other)
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

WrongAAnimal::~WrongAAnimal(void)
{
	std::cout << RED << "Destructor" << WHITE << " of " << BLUE << this->getClassName();
	std::cout << WHITE << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

const std::string	&WrongAAnimal::getType(void) const
{
	return (this->_type);
}

//==== member functions by me (for better testing)=======================================

std::string	WrongAAnimal::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}
