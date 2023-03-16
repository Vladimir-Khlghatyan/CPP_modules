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
    double penultimate;
    double last;

    this->strTrim(expression);
    this->removeUnnecessarySpaces(expression);
    if (expression == "")
    {
        std::cerr << RED << "Error: empty argument" << RESET << std::endl;
        return ;
    }
    if (this->checkAllowedSymbols(expression) == -1)
        return;
    std::string::iterator it;
    for (it = expression.begin(); it < expression.end(); ++it)
    {
        if (*it == ' ')
            continue ;
        if (std::isdigit(*it))
            _stack.push(static_cast<int>(*it) - '0');
        else if (_stack.size() >= 2)
        {
            last = static_cast<double>(_stack.top());
            _stack.pop();
            penultimate = static_cast<double>(_stack.top());
            _stack.pop();
            if (*it == '+')
                last = penultimate + last;
            else if (*it == '-')
                last = penultimate - last;
            else if (*it == '/')
            {
                if (last == 0)
                {
                    std::cerr << RED << "Error: division by zero." << RESET << std::endl;
                    while (!_stack.empty())
                        _stack.pop();
                    return ;
                }
                last = penultimate / last;
            }
            else if (*it == '*')
            {
                if (last != 0 && penultimate > std::numeric_limits<double>::max() / last)
                {
                    std::cerr << RED << "Error: double overflow." << RESET << std::endl;
                    while (!_stack.empty())
                        _stack.pop();
                    return ;
                }
                last = penultimate * last;
            }
            _stack.push(last);
        }
        else
        {
            std::cerr << RED << "Error: invalid Polish expression" << RESET << std::endl;
            while (!_stack.empty())
                _stack.pop();
            return ;
        }
    }
    if (it == expression.end() && _stack.size() == 1)
    {
        std::cout << _stack.top() << std::endl;
        while (!_stack.empty())
            _stack.pop();
    }


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
    size_t startPosition = str.find_first_not_of(" \f\n\r\t\v0123456789+-/*");
    if (startPosition != std::string::npos)
    {
        std::cerr << RED << "Error: unexpected symbol in the expression." << RESET << std::endl;
        return -1;
    }
    for (std::string::iterator it = str.begin(); it < str.end(); ++it)
    {
        if (std::isdigit(*it))
        {
            if (it != str.begin() && std::isdigit(*(it - 1)))
            {
                std::cerr << RED << "Error: the numbers must be single digits." << RESET << std::endl;
                return -1;
            }
        }
    }
    return 0;
}