#include "RPN.hpp"

int main(int ac, char **av)
{
    std::string expression;

    for (int i = 1; i < ac; ++i)
        expression += av[i];

    RPN rpn = RPN();

    rpn.expressionResult(expression);
    return (0); 
}