#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <limits>

# define RED    "\33[1;31m"
# define GREEN  "\33[1;32m"
# define YELLOW "\33[1;33m"
# define BLUE   "\33[1;34m"
# define PINK   "\33[1;35m"
# define CYAN   "\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"


class RPN
{
	private:
      std::stack<long long> _stack;

    public:		
      RPN(void);						          // Default constructor
      RPN(const RPN &other);			    // Copy constructor
      RPN &operator=(const RPN &rhs);	// Copy assignment operator
      ~RPN(void);						          // Destructor

    public:
      void    expressionResult(std::string expression);

    private:
      void    strTrim(std::string &str);
      void    removeUnnecessarySpaces(std::string &str);
      int     checkAllowedSymbols(std::string &str);
};

#endif