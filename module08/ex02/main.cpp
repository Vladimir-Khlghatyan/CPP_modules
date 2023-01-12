#include "MutantStack.hpp"

int main(void)
{
    std::cout << YELLOW << "\n--- TEST 1 -- (string MutantStack) ------------------------" << RESET << std::endl;
    std::cout << BLACK << "// MutantStack<std::string> string_mstack;\n" << std::endl;
    std::cout << BLACK << "// string_mstack.push(\"I\");" << std::endl;
    std::cout << BLACK << "// string_mstack.push(\"love\");" << std::endl;
    std::cout << BLACK << "// string_mstack.push(\"Tumo labs\");" << std::endl;
    std::cout << BLACK << "// string_mstack.pop();" << std::endl;
    std::cout << BLACK << "// string_mstack.push(\"fourty-two\");" << std::endl;
    std::cout << BLACK << "// string_mstack.push(\"Yerevan\");\n" << RESET << std::endl;
    

    MutantStack<std::string> string_mstack;
    string_mstack.push("I");
    string_mstack.push("love");
    string_mstack.push("Tumo labs");
    string_mstack.pop();
    string_mstack.push("fourty-two");
    string_mstack.push("Yerevan💚");

    MutantStack<std::string>::iterator str_b_it = string_mstack.begin();
    MutantStack<std::string>::iterator str_e_it = string_mstack.end();

    ++str_b_it;
    --str_b_it;
    std::cout << GREEN << "String_mstack iterator:";
    while (str_b_it != str_e_it)
    {
        std::cout << GREEN << " {";
        std::cout << WHITE << *str_b_it;
        std::cout << GREEN << "}";
        ++str_b_it;
    }
    std::cout << RESET << std::endl;

    std::cout << BLUE << "\n↓↓↓ String_mstack information ↓↓↓\n";
    std::cout << PINK << "Size: " << WHITE << string_mstack.size();
    std::cout << PINK  << "    Empty: " << WHITE << (string_mstack.empty() ? "true" : "false") << std::endl;
    
    long unsigned int size = string_mstack.size();
    for (long unsigned int i = 0; i < size; ++i)
        string_mstack.pop();
    std::cout << BLACK << "\n// for (int i = 0; i < size; ++i)\n//      string_mstack.pop();" << RESET << std::endl;
    std::cout << BLUE << "↓↓↓ String_mstack information ↓↓↓\n";
    std::cout << PINK << "Size: " << WHITE << string_mstack.size();
    std::cout << PINK  << "    Empty: " << WHITE << (string_mstack.empty() ? "true" : "false") << std::endl;



    std::cout << YELLOW << "\n--- TEST 2 -- (int MutantStack) ------------------------" << RESET << std::endl;
    std::cout << BLACK << "// MutantStack<int> int_mstack;\n" << std::endl;
    std::cout << BLACK << "// int_mstack.push(10);" << std::endl;
    std::cout << BLACK << "// int_mstack.push(15);" << std::endl;
    std::cout << BLACK << "// int_mstack.push(-24);" << std::endl;
    std::cout << BLACK << "// int_mstack.pop();" << std::endl;
    std::cout << BLACK << "// int_mstack.push(42);" << std::endl;
    

    MutantStack<int> int_mstack;
    int_mstack.push(10);
    int_mstack.push(15);
    int_mstack.push(-24);
    int_mstack.pop();
    int_mstack.push(42);

    MutantStack<int>::iterator int_b_it = int_mstack.begin();
    MutantStack<int>::iterator int_e_it = int_mstack.end();

    ++int_b_it;
    --int_b_it;
    std::cout << GREEN << "int_mstack iterator:";
    while (int_b_it != int_e_it)
    {
        std::cout << GREEN << " {";
        std::cout << WHITE << *int_b_it;
        std::cout << GREEN << "}";
        ++int_b_it;
    }
    std::cout << RESET << std::endl;

    std::cout << BLUE << "\n↓↓↓ Int_mstack information ↓↓↓\n";
    std::cout << PINK << "Size: " << WHITE << int_mstack.size();
    std::cout << PINK  << "    Empty: " << WHITE << (int_mstack.empty() ? "true" : "false") << std::endl;
    
    size = int_mstack.size();
    for (long unsigned int i = 0; i < size; ++i)
        int_mstack.pop();
    std::cout << BLACK << "\n// for (int i = 0; i < size; ++i)\n//      int_mstack.pop();" << RESET << std::endl;
    std::cout << BLUE << "↓↓↓ Int_mstack information ↓↓↓\n";
    std::cout << PINK << "Size: " << WHITE << int_mstack.size();
    std::cout << PINK  << "    Empty: " << WHITE << (int_mstack.empty() ? "true" : "false") << std::endl;
    return (0);
}
