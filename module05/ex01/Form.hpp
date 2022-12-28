#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;


	public:
		Form(void);														// Default constructor
		Form(std::string const &name, int signGrade, int executeGrade);	// Parameterized constructor
		Form(const Form &other);										// Copy constructor
		Form &operator=(const Form &other);								// Copy assignment operator
		~Form(void);													// Destructor

	public:
		class GradeTooHighException : public std::exception
		{
			const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what(void) const throw();
		};

	public:
		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
		const std::string	getClassName(void);
		void				beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif