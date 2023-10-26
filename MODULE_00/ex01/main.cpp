#include "PhoneBook.hpp"

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string str;
	std::cout << "****  use 'ADD' command to add a contact to the phonebook  *****.\n";
	std::cout << "****  use 'SEARCH' command to search for a specific contact  ***.\n";
	std::cout << "****  use 'EXIT' command to EXIT from the phonebook program  ***.\n";
	int i = 0;
	int k = 0;
	while (i <= 8)
	{
		std::getline (std::cin, str);
		if (str == "ADD")
		{
			std::cout << "First Name: \n";
			if (CheckEmptyField(str))
				contact.SetFirstName(str);
			std::cout << "Last Name: \n";
			if (CheckEmptyField(str))
				contact.SetLastName(str);
			std::cout << "Nick Name: \n";
			if (CheckEmptyField(str))
				contact.SetNickName(str);
			if (CheckPhoneNumber(str))
				contact.SetPhoneNumber(str);
			std::cout << "Darkest Secrect: \n";
			if (CheckEmptyField(str))
				contact.SetDarkestSecret(str);
			if(i == 8)
				i = 0;
			contact.SetIndex(i);
			phonebook.SetContact(contact, i);
			if (k < 8)
				k++;
			i++;
		}
		else if (str == "SEARCH")
		{
			std::cout << "| " << std::setw(10) << "index" << "| " << std::setw(10) << "First Name" << "| " << std::setw(10) << "Last Name" << "| " << std::setw(10) << "NickName" << "|\n";
			int j = 0;
			while (j < k)
			{
				std::cout << "| " << std::setw(10) << phonebook.GetContact(j).GetIndex() << "| ";
				if (phonebook.GetContact(j).GetFirstName().length() > 10)
					std::cout << phonebook.GetContact(j).GetFirstName().substr(0, 9) << ".| ";
				else
					std::cout << std::setw(10) << phonebook.GetContact(j).GetFirstName() << "| ";
				if (phonebook.GetContact(j).GetLastName().length() > 10)
					std::cout << phonebook.GetContact(j).GetLastName().substr(0, 9) << ".| ";
				else
					std::cout << std::setw(10) << phonebook.GetContact(j).GetLastName() << "| ";
				if (phonebook.GetContact(j).GetNickName().length() > 10)
					std::cout << phonebook.GetContact(j).GetNickName().substr(0, 9) << ".|\n";
				else
					std::cout << std::setw(10) << phonebook.GetContact(j).GetNickName() << "|\n";
				j++;
			}
			CheckIndex(str, phonebook, k);
		}
		else if (str == "EXIT")
			exit (EXIT_SUCCESS);
	}
}
