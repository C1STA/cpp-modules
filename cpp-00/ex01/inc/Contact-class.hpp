#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

class Contact
{
private:
	std::string	f_name;
	std::string	l_name;
	std::string	n_name;
	std::string	number;
	std::string	secret;
public:
	void	setFirstName();
	void	setLastName();
	void	setNickName();
	void	setPhoneNumber();
	void	setSecret();
	void	printContacts() const;
	void	search_print() const;
};

#endif