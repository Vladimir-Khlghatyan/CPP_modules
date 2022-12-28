#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <typeinfo>
# include <exception>
# include "Form.hpp"
# include <fstream>
# include <ctime>
# include <cstdlib>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;	

	public:
		Bureaucrat(void);									// Default constructor
		Bureaucrat(std::string const &name, int initGrade);	// Parameterized constructor
		Bureaucrat(const Bureaucrat &other);				// Copy constructor
		Bureaucrat &operator=(const Bureaucrat &other);		// Copy assignment operator
		~Bureaucrat(void);									// Destructor

	public:
		class GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};

	public:
		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		const std::string	getClassName(void);
		void				signForm(Form &f);
		void				executeForm(Form const &form);
};

// << overload
std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif