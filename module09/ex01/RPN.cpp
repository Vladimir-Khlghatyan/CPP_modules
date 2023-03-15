#include "RPN.hpp"

//==== constructors =====================================================================

RPN::RPN(void)
{
    // no code needed
}

RPN::RPN(const RPN &other)
{
    (void)&other;
    // no code needed
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		// no code needed
	}
	return (*this);
}

RPN::~RPN(void)
{
    // no code needed
}

//==== member functions =================================================================

void RPN::expressionResult(std::string expression)
{
    this->strTrim(expression);
    this->removeUnnecessarySpaces(expression);
    // std::cout << expression << std::endl;

}

void RPN::strTrim(std::string &str)
{
    size_t startPosition = str.find_first_not_of(" \f\n\r\t\v");
    if (startPosition != std::string::npos)
        str.erase(0, startPosition);

    size_t endPosition = str.find_last_not_of(" \f\n\r\t\v");
    if (endPosition != std::string::npos)
        str.erase(endPosition + 1);

    if (startPosition == std::string::npos && endPosition == std::string::npos)
        str.clear();
}

void RPN::removeUnnecessarySpaces(std::string &str)
{
    std::string new_str;
    bool        spaceAlreadyMet = false;

    for (std::string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (std::isspace(*it))
        {
            if (spaceAlreadyMet == false)
            {
                new_str += *it;
                spaceAlreadyMet = true;
            }
        }
        else
        {
            new_str += *it;
            spaceAlreadyMet = false;
        }
    }
    str = new_str;
}

int RPN::checkAllowedSymbols(std::string &str)
{
    (void)&str;
    return 0;
}