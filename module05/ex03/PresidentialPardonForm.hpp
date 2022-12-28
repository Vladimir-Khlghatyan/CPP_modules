#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;
class Form;

class PresidentialPardonForm : public Form
{
	private:
		std::string	_target;
	
	public:
		PresidentialPardonForm(void);											// Default constructor
		PresidentialPardonForm(std::string const &target);						// Parameterized constructor
		PresidentialPardonForm(const PresidentialPardonForm &other);			// Copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);	// Copy assignment operator
		~PresidentialPardonForm(void);											// Destructor

	public:
		const std::string			getClassName(void);
		void						execute(Bureaucrat const &executor) const;
		const std::string			getTarget(void) const;
};

#endif