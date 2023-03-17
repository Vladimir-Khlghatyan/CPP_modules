#include "RPN.hpp"

//==== constructors =====================================================================

RPN::RPN(void) { }
RPN::RPN(const RPN &other){ (void)&other; /*no code needed*/ }
RPN &RPN::operator=(const RPN &rhs) { if (this != &rhs) {/*no code needed*/} return *this; }
RPN::~RPN(void) { }

//==== member functions =================================================================

int RPN::expressionResult(std::string expression)
{
    double penultimate;
    double last;

    this->strTrim(expression);
    this->removeUnnecessarySpaces(expression);

    if (expression == "")
        return this->errorMsg("Error: empty argument");

    if (this->checkAllowedSymbols(expression) == -1)
        return -1;

    std::string::iterator it;
    for (it = expression.begin(); it < expression.end(); ++it)
    {
        if (*it == ' ')
            continue ;
        if (std::isdigit(*it))
            _stack.push(static_cast<float>(*it) - '0');
        else if (_stack.size() >= 2)
        {
            last = _stack.top();
            _stack.pop();
            penultimate = _stack.top();
            _stack.pop();
            if (*it == '+')
                last = penultimate + last;
            else if (*it == '-')
                last = penultimate - last;
            else if (*it == '/')
            {
                if (last == 0)
                    return this->errorMsg("Error: division by zero.");
                if (penultimate < std::numeric_limits<double>::min() * last)
                    return this->errorMsg("Error: double overflow (~0).");
                last = penultimate / last;
            }
            else if (*it == '*')
            {
                if (last != 0 && penultimate > std::numeric_limits<double>::max() / last)
                    return this->errorMsg("Error: double overflow (inf).");
                if (last != 0 && penultimate < std::numeric_limits<double>::lowest() / last)
                    return this->errorMsg("Error: double overflow (-inf).");
                last = penultimate * last;
            }
            _stack.push(last);
        }
        else
            return this->errorMsg("Error: incomplite Polish expression");
    }
    if (it == expression.end() && _stack.size() == 1)
    {
        std::cout << _stack.top() << std::endl;
        while (!_stack.empty())
            _stack.pop();
    }
    else
        this->errorMsg("Error: incomplite Polish expression");
    return 0;
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
        return this->errorMsg("Error: unexpected symbol in the expression.");

    for (std::string::iterator it = str.begin(); it < str.end(); ++it)
        if (std::isdigit(*it) && it != str.begin() && std::isdigit(*(it - 1)))
            return this->errorMsg("Error: the numbers must be single digits.");
    return 0;
}

int RPN::errorMsg(const std::string &msg)
{
    std::cerr << RED << msg << RESET << std::endl;
    while (!_stack.empty())
        _stack.pop();
    return -1;
}
