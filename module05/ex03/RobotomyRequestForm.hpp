#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;
class Form;

class RobotomyRequestForm : public Form
{
	private:
		std::string	_target;
	
	public:
		RobotomyRequestForm(void);											// Default constructor
		RobotomyRequestForm(std::string const &target);						// Parameterized constructor
		RobotomyRequestForm(const RobotomyRequestForm &other);				// Copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);	// Copy assignment operator
		~RobotomyRequestForm(void);											// Destructor

	public:
		const std::string			getClassName(void);
		void						execute(Bureaucrat const &executor) const;
		const std::string			getTarget(void) const;
};

#endif