#include "RPN.hpp"
#include <cstring>

int main(int argc, char **argv)
{
    std::string expression;

    if (argc != 2)
    {
        std::cerr << RED << "Error: the number of arguments must be 1." << RESET << std::endl;
        return 1;
    }
    expression = argv[argc - 1];
    

    RPN rpn = RPN();
    rpn.expressionResult(expression);

    return (0); 
}

// https://www.dcode.fr/reverse-polish-notation
