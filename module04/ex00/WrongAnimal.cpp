#include "WrongAnimal.hpp"

//==== constructors =====================================================================

WrongAnimal::WrongAnimal(void)
{
	this->_type = this->getClassName();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->_type = other._type;
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
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

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "Destructor" << WHITE << " of " << BLUE << this->getClassName();
	std::cout << WHITE << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED << "⚠️ I'm a generic Wronganimal, I don't have a unique sound🤷‍♂️" << RESET << std::endl;
}

const std::string	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

//==== member functions by me (for better testing)=======================================

std::string	WrongAnimal::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}
