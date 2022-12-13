#include <iostream>
#include <string>

#define RED		"\33[1;31m"
#define GREEN	"\33[1;32m"
#define PINK	"\33[1;35m"
#define YELLOW	"\33[1;33m"
#define BLUE	"\33[1;36m"
#define CYAN	"\33[1;37m"
#define WHITE	"\033[1;37m"
#define RESET	"\33[0;m"

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << RESET << "The memory address of the string variable is -> " << RED << &str << std::endl;
	std::cout << RESET << "The memory address held by stringPTR is ------> " << BLUE << stringPTR << std::endl;
	std::cout << RESET << "The memory address held by stringREF is ------> " << YELLOW << &stringREF << std::endl;

	std::cout << GREEN << "--------------------------------------------------------------" << std::endl;

	std::cout << RESET << "The value of the string variable is --------> " << RED << str << std::endl;
	std::cout << RESET << "The value pointed to by stringPTR is -------> " << BLUE << *stringPTR << std::endl;
	std::cout << RESET << "The value pointed to by stringREF is -------> " << YELLOW << stringREF << RESET << std::endl;
	return (0);
}
