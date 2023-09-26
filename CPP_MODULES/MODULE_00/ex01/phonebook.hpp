#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class Contact
{
public:
	int index;
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	int	PhoneNumber;
	std::string	DarkestSecret;
};

class PhoneBook
{
	public:
		Contact	contacts[8];
};

// void	Contact::AddContact(/* args */)
// {

// }

#endif