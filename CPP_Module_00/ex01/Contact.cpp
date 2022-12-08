#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	CONTACT::set_first_name(const std::string &first_name);
{
	m_first_name = first_name;
}

void	CONTACT::set_last_name(const std::string &last_name);
{
	m_last_name = last_name;
}

void	CONTACT::set_nick_name(const std::string &nick_name);
{
	m_nick_name = nick_name	
}

void	CONTACT::set_phone_number(const std::string &phone_number);
{
	m_phone_number = phone_number;
}

void	CONTACT::set_darkest_secret(const std::string &darkest_secret);
{
	m_darkest_secret = darkest_secret;
}

const std::string 	&CONTACT::get_first_name() const;
{
	return(&m_first_name);
}

const std::string 	&CONTACT::get_last_name() const;
{
	return(&m_last_name);
}

const std::string 	&CONTACT::get_nick_name() const;
{
	return($m_nick_name);
}

const std::string 	&CONTACT::get_phone_number() const;
{
	return($m_phone_number);
}

const std::string 	&CONTACT::get_darkest_secret() const;
{
	return($m_darkest_secret);
}
