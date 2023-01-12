#include "easyfind.hpp"

int main(void)
{
    std::vector<int>    myInts;
    
    myInts.push_back(10);
    myInts.push_back(15);
    myInts.push_back(100);
    myInts.push_back(24);

    //--------------------------------------------------------------------

    std::cout << BLACK << "// std::vector<int> myInts{10, 15, 100, 24};" << std::endl;
    std::cout << BLACK << "// easyfind(myInts, 42);" << RESET << std::endl;
    try {
        easyfind(myInts, 42); 
    }
    catch (const NotFoundException &e) {
        std::cerr << e.what() << std::endl;
    }

    //--------------------------------------------------------------------

    std::cout << BLACK << "\n// myInts.push_back(42);" << std::endl;
    std::cout << BLACK << "// easyfind(myInts, 42);" << RESET << std::endl;
    myInts.push_back(42);
    try {
        easyfind(myInts, 42); 
    }
    catch (const NotFoundException &e) {
        std::cerr << e.what() << std::endl;
    }

    //--------------------------------------------------------------------

    std::cout << BLACK << "\n// easyfind(myInts, 24);" << RESET << std::endl;
    try {
        easyfind(myInts, 24); 
    }
    catch (const NotFoundException &e) {
        std::cerr << e.what() << std::endl;
    }

    //--------------------------------------------------------------------

    std::cout << BLACK << "\n// mmyInts.erase(myInts.begin() + 2);" << std::endl;
    std::cout << BLACK << "// easyfind(myInts, 100);" << RESET << std::endl;
    myInts.erase(myInts.begin() + 2);
    try {
        easyfind(myInts, 100); 
    }
    catch (const NotFoundException &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
