#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;
class Form;

class Intern
{
	public:
		Intern(void);							// Default constructor
		Intern(const Intern &other);			// Copy constructor
		Intern &operator=(const Intern &other);	// Copy assignment operator
		~Intern(void);							// Destructor

	public:
		class InternException : public std::exception
		{
			const char	*what(void) const throw();
		};

	public:
		const std::string	getClassName(void);
		Form				*makeForm(const std::string &formName, const std::string &formTarget) const;

	private:
		Form	*makeP(const std::string &target) const;
		Form	*makeR(const std::string &target) const;
		Form	*makeSh(const std::string &target) const;
};

#endif