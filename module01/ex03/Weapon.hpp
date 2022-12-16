#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Weapon
{
	public:

		Weapon(const std::string type);
		~Weapon();
		const std::string&	getType(void) const;
		void				setType(const std::string newType);

	private:

		std::string	m_type;
};

#endif
