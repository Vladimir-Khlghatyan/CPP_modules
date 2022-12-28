#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;
class Form;

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;
	
	public:
		ShrubberyCreationForm(void);											// Default constructor
		ShrubberyCreationForm(std::string const &target);						// Parameterized constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);				// Copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);	// Copy assignment operator
		~ShrubberyCreationForm(void);											// Destructor

	public:
		const std::string			getClassName(void);
		void						execute(Bureaucrat const &executor) const;
		const std::string			getTarget(void) const;
};

#endif