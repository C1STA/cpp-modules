#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact-class.hpp"

class	PhoneBook
{
private:
	int			i;
	bool		full;
	Contact		contact[8];
public:
	PhoneBook();
	void	add();
	void	search();
	void	setContact();
	void	displayContact();
};

#endif