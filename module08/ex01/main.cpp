#include "Span.hpp"

static void pushRandomNums(std::vector<int> &vec, int size)
{
    struct  timeval currentTime;
    int     sign;
    for (int i = 0; i < size; ++i)
    {
        gettimeofday(&currentTime, NULL);
        std::srand(currentTime.tv_usec);
        sign = 1;
        if (std::rand() % 2)
            sign = -1;
        vec.push_back(std::rand() * sign);
    }
}

int main(void)
{
    std::cout << YELLOW << "\n--- TEST 1 ------------------------------------------";
    std::cout << "------------------------------------------" << RESET << std::endl;

    Span    s1(4);
    
    try {
        s1.addNumber(8);
        s1.addNumber(5);
        s1.addNumber(42);
        s1.addNumber(24);
        s1.addNumber(60);
    }
    catch (const Span::SpanIsFullException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try {
        s1.shortestSpan();
        s1.longestSpan();
    }
    catch (const Span::NotEnoughElementsException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n--- TEST 2 ------------------------------------------";
    std::cout << "------------------------------------------" << RESET << std::endl;

    Span    s2(9000);
    std::vector<int>    big;
    pushRandomNums(big, 11000);
    try {
        s2.addRange(big.begin(), big.end());
    }
    catch (const Span::NotEnoughSpaceException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try {
        s2.shortestSpan();
    }
    catch (const Span::NotEnoughElementsException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    s2.addNumber(63);
    try {
        s2.longestSpan();
    }
    catch (const Span::NotEnoughElementsException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    s2.addNumber(105);
    try {
        s2.shortestSpan();
        s2.longestSpan();
    }
    catch (const Span::NotEnoughElementsException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n--- TEST 3 ------------------------------------------";
    std::cout << "------------------------------------------" << RESET << std::endl;
    
    Span    s3(12000);
    try {
        s3.addRange(big.begin(), big.end());
    }
    catch (const Span::NotEnoughSpaceException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try {
        s3.shortestSpan();
        s3.longestSpan();
    }
    catch (const Span::NotEnoughElementsException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
