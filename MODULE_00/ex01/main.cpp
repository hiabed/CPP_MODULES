#include "phonebook.hpp"

void CheckIndex(std::string CheckIn, PhoneBook phonebook, int k)
{
	while (1)
	{
		std::cout << "Please type an index of a contact: \n";
		std::cin >> CheckIn;
		if (CheckIn.length() == 1 && CheckIn[0] - 48 > 0 && CheckIn[0] - 48 <= k)
		{
			std::cout << "First Name: " << phonebook.contacts[CheckIn[0] - 49].GetFirstName() << "\n";
			std::cout << "Last Name: " << phonebook.contacts[CheckIn[0] - 49].GetLastName() << "\n";
			std::cout << "Nick Name: " << phonebook.contacts[CheckIn[0] - 49].GetNickName() << "\n";
			std::cout << "Phone number: " << phonebook.contacts[CheckIn[0] - 49].GetPhoneNumber() << "\n";
			std::cout << "Darkest Secret: " << phonebook.contacts[CheckIn[0] - 49].GetDarkestSecret() << "\n";
			std::cout << "Index: " << phonebook.contacts[CheckIn[0] - 49].index << "\n";
			break;
		}
		else
		{
			std::cout << "Invalid index.\n";
			continue;
		}
	}
}

int	CheckEmptyField(std::string &Field)
{
	int i = 0;
	while (1)
	{
		std::getline (std::cin, Field);
		if (Field.empty())
		{
			std::cout << "Field's empty, try again:\n";
			continue;
		}
		else
		{
			while (Field[i] && (Field[i] == ' ' || Field[i] == '\t' || Field[i] == '\n'))
				i++;
			if(!Field[i])
				std::cout << "Field's empty, try again:\n";
			else
				return 1;
		}
	}
}

int	CheckPhoneNumber(std::string &PhoneNum)
{
	std::cout << "Phone Number: \n";
	while (1)
	{
		std::getline (std::cin, PhoneNum);
		int j = 0;
		while (isdigit(PhoneNum[j]))
			j++;
		if (PhoneNum[j] != '\0')
		{
			std::cout << "invalid, try again:\n";
			continue;
		}
		return 1;
	}
}

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string PhoneNum;
	std::string check_val;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkestSecret;
	std::string CheckIn;
	std::cout << "****  use 'ADD' command to add a contact to the phonebook  *****.\n";
	std::cout << "****  use 'SEARCH' command to search for a specific contact  ***.\n";
	std::cout << "****  use 'EXIT' command to EXIT from the phonebook program  ***.\n";
	int i = 0;
	int k = 0;
	while (i <= 8)
	{
		std::getline (std::cin, check_val);
		if (check_val == "ADD")
		{
			std::cout << "First Name: \n";
			if (CheckEmptyField(FirstName))
				contact.SetFirstName(FirstName);
			std::cout << "Last Name: \n";
			if (CheckEmptyField(LastName))
				contact.SetLastName(LastName);
			std::cout << "Nick Name: \n";
			if (CheckEmptyField(NickName))
				contact.SetNickName(NickName);
			if (CheckPhoneNumber(PhoneNum))
				contact.SetPhoneNumber(PhoneNum);
			std::cout << "Darkest Secrect: \n";
			if (CheckEmptyField(DarkestSecret))
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
			std::cout << "| " << std::setw(10) << "index" << "| " << std::setw(10) << "First Name" << "| " << std::setw(10) << "Last Name" << "| " << std::setw(10) << "NickName" << "|\n";
			int j = 0;
			while (j < k)
			{
				std::cout << "| " << std::setw(10) << phonebook.contacts[j].index << "| ";
				if (phonebook.contacts[j].GetFirstName().length() > 10)
					std::cout << phonebook.contacts[j].GetFirstName().substr(0, 9) << ".| ";
				else
					std::cout << std::setw(10) << phonebook.contacts[j].GetFirstName() << "| ";
				if (phonebook.contacts[j].GetLastName().length() > 10)
					std::cout << phonebook.contacts[j].GetLastName().substr(0, 9) << ".| ";
				else
					std::cout << std::setw(10) << phonebook.contacts[j].GetLastName() << "| ";
				if (phonebook.contacts[j].GetNickName().length() > 10)
					std::cout << phonebook.contacts[j].GetNickName().substr(0, 9) << ".|\n";
				else
					std::cout << std::setw(10) << phonebook.contacts[j].GetNickName() << "|\n";
				j++;
			}
			CheckIndex(CheckIn, phonebook, k);
		}
		else if (check_val == "EXIT")
			exit (EXIT_SUCCESS);
	}
}
