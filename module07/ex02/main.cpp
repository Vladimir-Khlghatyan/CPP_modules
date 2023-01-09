#include "Array.hpp"

// this is subject main
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main(void)
{
    Array<char> carr(5);
    carr[0] = 'B';
    carr[1] = 'a';
    carr[2] = 'r';
    carr[3] = 'e';
    carr[4] = 'v';


    Array<float> farr(3);
    farr[0] = 24.42;
    farr[1] = 42.24;
    farr[2] = 100.01;

    Array<std::string> sarr(3);
    sarr[0] = "I";
    sarr[1] = "Love";
    sarr[2] = "Armenia❤️ 💙🧡";

    std::cout << YELLOW << "\n======= BASIC TESTS ============================" << RESET << std::endl;

    std::cout << GREEN << "CHAR ARRAY: " << RESET;
    std::cout << BLUE << "size = " << carr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < carr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << carr[i] << RESET;

    std::cout << GREEN << "\n\nFLOAT ARRAY: " << RESET;
    std::cout << BLUE << "size = " << farr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < farr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << farr[i] << RESET;

    std::cout << GREEN << "\n\nSTRING ARRAY: " << RESET;
    std::cout << BLUE << "size = " << sarr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr[i] << RESET;

    std::cout << YELLOW << "\n\n======= EXCEPTIONS ============================" << RESET << std::endl;

    try {
        std::cout << WHITE << sarr[2] << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << WHITE << sarr[-1] << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << WHITE << sarr[5] << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << WHITE << farr[1] << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << WHITE << farr[10] << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << YELLOW << "\n======= COPY CONSTRUCTOR (deep copy) ==========" << RESET << std::endl;

    std::cout << GREEN << "STRING ARRAY: " << RESET;
    std::cout << BLUE << "size = " << sarr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr[i] << RESET;

    Array<std::string> sarr_copy(sarr);

    std::cout << GREEN << "\n\nSTRING ARRAY_COPY: " << RESET;
    std::cout << BLUE << "size = " << sarr_copy.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr_copy.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr_copy[i] << RESET;

    std::cout << PINK << "\n\n----- change string array[2] to \"Yerevan💚\"-----" << RESET << std::endl;
    sarr[2] = "Yerevan💚";

    std::cout << GREEN << "STRING ARRAY: " << RESET;
     std::cout << BLUE << "size = " << sarr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr[i] << RESET;

    std::cout << GREEN << "\n\nSTRING ARRAY_COPY: " << RESET;
    std::cout << BLUE << "size = " << sarr_copy.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr_copy.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr_copy[i] << RESET;

    std::cout << YELLOW << "\n\n======= ASSIGNMENT OPERATOR (deep) ============" << RESET << std::endl;

    std::cout << GREEN << "STRING ARRAY: " << RESET;
    std::cout << BLUE << "size = " << sarr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr[i] << RESET;

    Array<std::string> sarr_new(4);

    std::cout << GREEN << "\n\nSTRING ARRAY_NEW: " << RESET;
    std::cout << BLUE << "size = " << sarr_new.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr_new.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr_new[i] << RESET;

    std::cout << PINK << "\n\n----- array_new = array ----------------------" << RESET << std::endl;
    sarr_new = sarr;

    std::cout << GREEN << "STRING ARRAY: " << RESET;
    std::cout << BLUE << "size = " << sarr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr[i] << RESET;

    std::cout << GREEN << "\n\nSTRING ARRAY_NEW: " << RESET;
    std::cout << BLUE << "size = " << sarr_new.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr_new.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr_new[i] << RESET;

    std::cout << PINK << "\n\n----- change string array[2] to \"Martuni💖\"-----" << RESET << std::endl;
    sarr[2] = "Martuni💖";

    std::cout << GREEN << "STRING ARRAY: " << RESET;
    std::cout << BLUE << "size = " << sarr.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr[i] << RESET;

    std::cout << GREEN << "\n\nSTRING ARRAY_NEW: " << RESET;
    std::cout << BLUE << "size = " << sarr_new.size() << RESET << std::endl;
    for (unsigned int i = 0; i < sarr_new.size(); ++i)
        std::cout << BLACK<< " item[" << i << "]: " << WHITE << sarr_new[i] << RESET;

    std::cout << "\n" << std::endl;    
    return (0);
}


