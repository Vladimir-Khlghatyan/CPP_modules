#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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


class WrongAnimal
{
	protected:
		std::string	_type;		

	public:		
		WrongAnimal(void);									// Default constructor
		WrongAnimal(const WrongAnimal &other);				// Copy constructor
		WrongAnimal &operator=(const WrongAnimal &other);	// Copy assignment operator
		virtual ~WrongAnimal(void);							// Destructor

	public:
		void				makeSound(void) const;
		const std::string	&getType(void) const;
		

	public:
		std::string	getClassName(void);

};

#endif