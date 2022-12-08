
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		void		add_contact(std::string fields[5]);
		void		display_phonebook() const;
		void		display_contact(int index) const;
		int			get_size() const;
	private:
		Contact		_contacts[8];
		int			_size;
		int			_insert_index;
};

#endif
