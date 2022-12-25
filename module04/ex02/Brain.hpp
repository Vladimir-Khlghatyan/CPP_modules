#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <typeinfo>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"


class Brain
{
	private:
		std::string	_ideas[100];

	public:		
		Brain(void);							// Default constructor
		Brain(const Brain &other);				// Copy constructor
		Brain &operator=(const Brain &other);	// Copy assignment operator
		virtual ~Brain(void);					// Destructor

	public:
		void				setIdea(int index, const std::string& idea);
		const std::string	&getIdea(int index) const;
		std::string			getClassName(void);

};

#endif