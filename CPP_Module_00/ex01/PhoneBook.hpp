#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define PINK	"\33[1;35m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;36m"
# define CYAN	"\33[1;37m"
# define WHITE	"\033[1;37m"
# define RESET	"\33[0;m"

class PhoneBook
{
	public:

		PhoneBook();
		~PhoneBook();
		void	set_contact(std::string fields[5]);
		void	print_phonebook() const;
		void	print_contact(int index) const;

	private:

		int		m_size {0};
		int		m_index {0};
		Contact	m_contact[8];

};