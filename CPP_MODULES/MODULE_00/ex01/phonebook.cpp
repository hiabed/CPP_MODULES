#include "phonebook.hpp"

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string check_val;\
	int i = 0;
	while (i < 8)
	{
		std::cin >> check_val;
		if (check_val == "ADD")
		{
			std::cout << "First Name: \n";
			std::cin >> contact.FirstName;
			std::cout << "Last Name: \n";
			std::cin >> contact.LastName;
			std::cout << "Nick Name: \n";
			std::cin >> contact.NickName;
			while (1)
			{
				std::cout << "Phone Number: \n";
				std::cin >> contact.PhoneNumber;
				int j = 0;
				while (isdigit(contact.PhoneNumber[j]))
					j++;
				if(contact.PhoneNumber[j] == '\0')
					break;
				else
					std::cout << "Invalid input. You should enter only digits in this field.\n";
			}
			std::cout << "Darkest Secrect: \n";
			std::cin >> contact.DarkestSecret;
			contact.index = i;
			phonebook.contacts[i] = contact;
		}
		else if (check_val == "SEARCH")
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << "| " << phonebook.contacts[j].index << " | ";
				std::cout << phonebook.contacts[j].FirstName << " | ";
				std::cout << phonebook.contacts[j].LastName << " | ";
				std::cout << phonebook.contacts[j].NickName << " |\n";
			}
		}
		else if (check_val == "EXIT")
			exit (EXIT_SUCCESS);
		if (i == 7)
			i = 0; 
		i++;
	}
}