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