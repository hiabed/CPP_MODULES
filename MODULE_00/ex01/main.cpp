#include "phonebook.hpp"

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string check_val;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	int i = 0;
	int k = 0;
	std::string CheckIndex;
	while (i <= 8)
	{
		std::getline (std::cin, check_val);
		if (check_val == "ADD")
		{
			std::cout << "First Name: \n";
			std::getline (std::cin, FirstName);
			contact.SetFirstName(FirstName);
			std::cout << "Last Name: \n";
			std::getline (std::cin, LastName);
			contact.SetLastName(LastName);
			std::cout << "Nick Name: \n";
			std::getline (std::cin, NickName);
			contact.SetNickName(NickName);
			while (1)
			{
				std::cout << "Phone Number: \n";
				std::getline (std::cin, PhoneNumber);
				int j = 0;
				while (isdigit(PhoneNumber[j]))
					j++;
				if(PhoneNumber[j] != '\0')
				{
					std::cout << "Invalid input. You should enter only digits in this field.\n";
					continue;
				}
				contact.SetPhoneNumber(PhoneNumber);
				break;
			}
			std::cout << "Darkest Secrect: \n";
			std::getline (std::cin, DarkestSecret);
			contact.SetDarkestSecret(DarkestSecret);
			if(i == 8)
				i = 0;
			contact.index = i + 1;
			phonebook.contacts[i] = contact;
			if (k < 8)
				k++;
			i++;
		}
		else if (check_val == "SEARCH")
		{
			int j = 0;
			while (j < k)
			{
				if(phonebook.contacts[j].GetFirstName()[0] != '\0')
				{
					std::cout << "| " << phonebook.contacts[j].index << " | ";
					std::cout << phonebook.contacts[j].GetFirstName().substr(0, 10) << "	| ";
					std::cout << phonebook.contacts[j].GetLastName().substr(0, 10) << "	| ";
					std::cout << phonebook.contacts[j].GetNickName().substr(0, 10) << "	|\n";
				}
				j++;
			}
			std::cout << "Please type an index of a contact: \n";
			std::cin >> CheckIndex;
			if (CheckIndex.length() == 1 && CheckIndex[0] - 48 > 0 && CheckIndex[0] - 48 <= k)
			{
				std::cout << "First Name: " << phonebook.contacts[CheckIndex[0] - 49].GetFirstName() << "\n";
				std::cout << "Last Name: " << phonebook.contacts[CheckIndex[0] - 49].GetLastName() << "\n";
				std::cout << "Nick Name: " << phonebook.contacts[CheckIndex[0] - 49].GetNickName() << "\n";
				std::cout << "Phone number: " << phonebook.contacts[CheckIndex[0] - 49].GetPhoneNumber() << "\n";
				std::cout << "Darkest Secret: " << phonebook.contacts[CheckIndex[0] - 49].GetDarkestSecret() << "\n";
				std::cout << "Index: " << phonebook.contacts[CheckIndex[0] - 49].index << "\n";
			}
			else
				std::cout << "Invalid\n";
		}
		else if (check_val == "EXIT")
			exit (EXIT_SUCCESS);
	}
}
