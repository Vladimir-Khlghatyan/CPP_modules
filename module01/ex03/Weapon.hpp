#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define PINK	"\33[1;35m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;36m"
# define CYAN	"\33[1;37m"
# define WHITE	"\033[1;37m"
# define RESET	"\33[0;m"

class Weapon
{
	public:

		Weapon();
		Weapon(const std::string type);
		~Weapon();
		const std::string&	getType(void) const;
		void	setType(const std::string newType);

	private:
		std::string	m_type;	
};

#endif