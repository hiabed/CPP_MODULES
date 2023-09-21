#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class Contact
{
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	int	PhoneNumber;
	std::string	DarkestSecret;
	void	AddContact(std::string FirstName, std::string LastName, std::string NickName, int PhoneNumber, std::string DarkestSecret)
	{
		
	}
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