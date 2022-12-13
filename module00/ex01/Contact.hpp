#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:

		Contact();
		~Contact();
		void				set_first_name(const std::string &first_name);
		void				set_last_name(const std::string &last_name);
		void				set_nick_name(const std::string &nick_name);
		void				set_phone_number(const std::string &phone_namber);
		void				set_darkest_secret(const std::string &darkest_secret);
		const std::string 	&get_first_name() const;
		const std::string 	&get_last_name() const;
		const std::string 	&get_nick_name() const;
		const std::string 	&get_phone_number() const;
		const std::string 	&get_darkest_secret() const;

	private:

		std::string 		m_first_name;
		std::string 		m_last_name;
		std::string 		m_nick_name;
		std::string 		m_phone_number;
		std::string 		m_darkest_secret;	
};

#endif