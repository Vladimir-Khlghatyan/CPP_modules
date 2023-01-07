#include "Data.hpp"

//==== constructors =====================================================================

Data::Data(void) : _value("") {}

Data::Data(std::string const &value) : _value(value) {}

Data::Data(const Data &other) : _value(other._value) {}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Data::~Data(void) {}

//==== member functions by me (for better testing)=======================================

const std::string	Data::getValue(void) const
{
	return(_value);
}

